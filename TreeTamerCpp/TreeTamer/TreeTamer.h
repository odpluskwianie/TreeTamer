#pragma once
#include <list>
#include <map>
#include <concepts>
#include <memory>
#include <functional>

namespace TreeTamer
{
	template<typename PathType>
	concept TreePath = requires(const PathType& p, const PathType& q)
	{
		{ p.operator==(q) } -> std::same_as<bool>;
		{ p.startsWith(q) } -> std::same_as<bool>;
		{ p.getLength() } -> std::same_as<int>;
	};

	template<typename T, typename DataType>
	concept TreeIterator = requires(T iterator) {
		{ iterator.hasNext() } -> std::convertible_to<bool>;
		{ iterator.nextSibling() };
		{ iterator.hasChildren() } -> std::convertible_to<bool>;
		{ iterator.currentDepth() } -> std::same_as<int>;
		{ iterator.firstChild() };
		{ iterator.parent() };
		{ iterator.hasParent() } -> std::convertible_to<bool>;
		{ iterator.operator*() } -> std::same_as<DataType>;
	};

	template<typename T, typename DataType>
	concept IIterableTree = requires(T tree) {
		{ tree.getIterator() } -> TreeIterator<DataType>;
	};

	template <typename DataType, typename PathType, typename TreeType>
		requires TreePath<PathType> && IIterableTree<TreeType, DataType>
	class TreeTamerConfig
	{
		std::list<PathType> paths;
		TreeType data;
		std::function <void(std::map<PathType, DataType>)> onDataEntryFulfilledCallback;

	public:
		TreeTamerConfig(TreeType data, std::list<PathType> paths, std::function <void(std::map<PathType, DataType>)> onDataEntryFulfilledCallback) : paths(paths), data(data), onDataEntryFulfilledCallback(onDataEntryFulfilledCallback){}
	};

	template <typename DataType, typename TreeType, typename IteratorType, typename PathType>
		requires TreeIterator<IteratorType, DataType>&& IIterableTree<TreeType, DataType>&& TreePath<PathType>
	class TreeTamer
	{
	private:
		TreeType tree;
		IteratorType iterator;
		std::list<PathType> paths;
		std::function <void(std::map<PathType, DataType>)> onDataEntryFulfilledCallback;

	public:
		TreeTamer() = default;
		virtual ~TreeTamer() = default;
		void init(TreeTamerConfig<PathType, DataType, TreeType>& config)
		{
			tree = config.data;
			paths = config.paths;
			onDataEntryFulfilledCallback = config.onDataEntryFulfilledCallback;
			iterator = tree.getIterator();
		}
		
		void processTree(int currentDepth = 0, std::map<PathType, DataType>& outputData = {})
		{
			//let's begin from iterate over the tree
			//outputData[tree.current().getPath()] = *tree;



			do
			{
				if (*tree.getPath().getLength() > 1) // MINUS CURRENT DEPTH
					;//get into the subtree
				else switch (tree.current().getPath().getLength())
				{
				case 1:
					//add to curent results array and process it by the callback, THEN CLEAR RESULTS FROM EXITED NODE
					break;
				case 0:
					//do nothing
					break;
				default:
					throw std::exception("Invalid path length");
				}


				processTree(currentDepth);
				if (false/*node.hasSubtree()*/)
				{
					//node.deeper();
					/*auto subtree = node.getSubtree();
					while (subtree.hasNext())
					{
						auto subNode = subtree.next();
						processTree(subNode);
					}*/

				}
				
				tree.next();
			} while (tree.hasNext());
		}
	};
}