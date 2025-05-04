#pragma once
#include "../TreeTamer/TreeTamer.h"
#include "string"

namespace TreeTamerTinyXml2
{
	//template<typename stringType = std::wstring>
	//class TreeTamerXmlPath
	//{
	//	const std::vector<stringType> path;
	//public:
	//	TreeTamerXmlPath(std::vector<stringType> path) : path(path) {}
	//	TreeTamerXmlPath(TreeTamerXmlPath&& other) : path(std::move(other.path)) {}
	//	TreeTamerXmlPath(const TreeTamerXmlPath& other) : path(other.path) {}
	//	bool operator==(const TreeTamerXmlPath& other) const
	//	{
	//		return path == other.path;
	//	}
	//	bool startsWith(const TreeTamerXmlPath& other) const
	//	{
	//		if (other.path.size() > path.size())
	//			return false;
	//		for (size_t i = 0; i < other.path.size(); ++i)
	//		{
	//			if (path[i] != other.path[i])
	//				return false;
	//		}
	//		return true;
	//	}
	//	size_t getLength() const
	//	{
	//		return path.size();
	//	}

	//};
	//class TreeTamerXmlIterator
	//{
	//	boost::property_tree::ptree::iterator current;
	//	boost::property_tree::ptree::iterator end;
	//	int depth;
	//	std::vector<boost::property_tree::ptree::iterator> parents;
	//public:
	//	bool hasNext()
	//	{
	//		return current != end;
	//	}
	//	void nextSibling()
	//	{
	//		if (current != end)
	//			++current;
	//	}
	//	bool hasChildren()
	//	{
	//		return current->second.size() > 0;
	//	}
	//	int currentDepth()
	//	{
	//		return depth;
	//	}
	//	void firstChild()
	//	{
	//		if (current != end)
	//		{
	//			parents.push_back(current);
	//			current = current->second.begin();
	//			++depth;
	//		}
	//	}
	//	void parent()
	//	{
	//		if (!parents.empty())
	//		{
	//			current = parents.back();
	//			parents.pop_back();
	//			--depth;
	//		}
	//		else
	//		{
	//			throw std::runtime_error("No parent available");
	//		}
	//	}
	//	bool hasParent()
	//	{
	//		return !parents.empty();
	//	}
	//	std::string operator*()
	//	{
	//		return current->first;
	//	}


	//};
	//class TreeTamerXml
	//{

	//};

	//class TreeTamerXml : public TreeTamer::TreeTamer<std::string, boost::property_tree::ptree, boost::property_tree::ptree::iterator, std::vector<std::string>>//TODO: implement iterator that fits the concept
	//{
	//public:
	//	TreeTamerXml();
	//	~TreeTamerXml();
	//};
}
