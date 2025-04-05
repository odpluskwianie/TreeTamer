#pragma once

namespace TreeTamer
{
	template <typename PathType, typename DataType>
	class ITreeDataPathable
	{
	public:
		virtual ~ITreeDataPathable() = default;
		virtual PathType getPath() const = 0;
		virtual void setPath(const PathType& path) = 0;
		virtual DataType getData() const = 0;
	};

	template <typename DataType>
	class ITreeDataIterable
	{
	public:
		bool hasNext() const = 0;
		DataType next() = 0;
		DataType current() const = 0;
		DataType hasSubtree() const = 0;
		ITreeDataIterable<DataType> getSubtree() const = 0;
	};

	template <typename T>
	class TreeTamerConfig
	{
		std::list<T> paths;
		TreeTamerData<T> data;

	public:
		TreeTamerConfig(data, paths) : paths(paths), data(data) {}
	};

	class TreeTamerBase
	{
	public:
		TreeTamerBase() = default;
		virtual ~TreeTamerBase() = default;
		virtual void processTree() = 0;
	};
}