#pragma once
#include <list>

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

	public:
		TreeTamerConfig(data, paths) : paths(paths), data(data) {}
	};

	template <typename PathType, typename DataType>
	class TreeTamerBase
	{
	public:
		TreeTamerBase() = default;
		virtual ~TreeTamerBase() = default;
		virtual void init(TreeTamerConfig<PathType, DataType> t) = 0;
		virtual void processTree() = 0;
	};
}