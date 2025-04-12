#pragma once
#include <list>
#include <map>
#include <concepts>
#include <memory>

namespace TreeTamer
{
	///TODO: concepts of DataType i PathType 

	template<typename T>
	concept TreeIterator = requires(T iterator) {
		{ iterator.hasNext() } -> std::convertible_to<bool>;
		{ iterator.next() };
		{ iterator.hasChildren() } -> std::convertible_to<bool>;
		{ iterator.currentDepth() } -> std::same_as<int>;
		{ iterator.deeper() };
		{ iterator.shallower() };
		{ iterator.hasParent() } -> std::convertible_to<bool>;
	};

	template<typename T>
	concept IIterableTree = requires(T tree) {
		{ tree.getIterator() } -> TreeIterator;
	};

	template <typename PathType, typename DataType, IIterableTree IterableTreeDataType>
	class TreeTamerConfig
	{
		std::list<PathType> paths;
		IterableTreeDataType data;
		std::function <void(std::map<PathType, DataType>)> onDataEntryFulfilledCallback;

	public:
		TreeTamerConfig(data, paths, onDataEntryFulfilledCallback) : paths(paths), data(data), onDataEntryFulfilledCallback(onDataEntryFulfilledCallback){}
	};

	template <typename PathType, typename DataType, typename IterableTreeDataType >//IIterableTreeData replace by template to increase processing speed? AND USE CONCEPTS FROM C++20!!!!!!oneoneone
	class TreeTamer
	{
	private:
		IterableTreeDataType/*<PathType, DataType>*/ treeData;///////
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
			//let's begin from iterate over the tree
			outputData.at(treeData.current().getPath()) = treeData.current().getData();
			while (treeData.hasNext())
			{
				if (treeData.current().getPath().getLength() > 1) // MINUS CURRENT DEPTH
					//get into the subtree
				else switch (treeData.current().getPath().getLength())
				{
				case 1:
					//add to curent results array and process it by the callback, THEN CLEAR RESULTS FROM EXITED NODE
					break;
				case 0:
					//do nothing
					break;
				default:
					throw std::exception("Invalid path length");//


				processTree(currentDepth);
				if (node.hasSubtree())
				{
					node.deeper();
					/*auto subtree = node.getSubtree();
					while (subtree.hasNext())
					{
						auto subNode = subtree.next();
						processTree(subNode);
					}*/

				}
				
				treeData.next();
			}
		}
	};
}