#pragma once
#include <list>
#include <map>

namespace TreeTamer
{
	template <typename PathType, typename DataType>
	class IPathableTreeDataEntry
	{
	public:
		virtual ~IPathableTreeDataEntry() = default;
		virtual PathType getPath() const = 0;
		virtual void setPath(const PathType& path) = 0;
		virtual DataType getData() const = 0;
	};

	template <typename PathType, typename DataType>
	class IIterableTreeData
	{
	public:
		bool hasNext() const = 0;
		IPathableTreeDataEntry<PathType, DataType> next() = 0;
		IPathableTreeDataEntry<PathType, DataType> current() const = 0;
		IPathableTreeDataEntry<PathType, DataType> hasSubtree() const = 0;
		IIterableTreeData<PathType, DataType> getSubtree() const = 0;
	};

	template <typename PathType, typename DataType>
	class TreeTamerConfig
	{
		std::list<PathType> paths;
		IIterableTreeData<PathType, DataType> data;
		std::function <void(std::map<PathType, DataType>)> onDataEntryFulfilledCallback;

	public:
		TreeTamerConfig(data, paths, onDataEntryFulfilledCallback) : paths(paths), data(data), onDataEntryFulfilledCallback(onDataEntryFulfilledCallback){}
	};

	template <typename PathType, typename DataType>
	class TreeTamerBase
	{
	public:
		TreeTamerBase() = default;
		virtual ~TreeTamerBase() = default;
		virtual void init(TreeTamerConfig<PathType, DataType>& t) = 0;
		virtual void processTree() = 0;
	};

	template <typename PathType, typename DataType>//IIterableTreeData replace by template to increase processing speed?
	class TreeTamer : public TreeTamerBase<PathType, DataType>
	{
	private:
		IIterableTreeData<PathType, DataType> treeData;///////
		std::list<PathType> paths;
		std::function <void(std::map<PathType, DataType>)> onDataEntryFulfilledCallback;

	public:
		TreeTamer() = default;
		virtual ~TreeTamer() = default;
		void init(TreeTamerConfig<PathType, DataType>& config) override
		{
			treeData = config.data;
			paths = config.paths;
			onDataEntryFulfilledCallback = config.onDataEntryFulfilledCallback;
		}
		
		void processTree(int currentDepth = 0, std::map<PathType, DataType>& outputData) override
		{
			outputData.at(treeData.current().getPath()) = treeData.current().getData();
			while (treeData.hasNext())
			{
				if (treeData.current().getPath().getLength() > 1)
					//get into the subtree
				else switch (treeData.current().getPath().getLength())
				{
				case 1:
					//add to curent results array and process it by the callback
					break;
				case 0:
					//do nothing
					break;
				default:
					throw std::exception("Invalid path length");//


				auto node = treeData.next();
				processTree(currentDepth);
				if (node.hasSubtree())
				{
					auto subtree = node.getSubtree();
					while (subtree.hasNext())
					{
						auto subNode = subtree.next();
						processTree(subNode);
					}
				}
			}
		}
	};
}