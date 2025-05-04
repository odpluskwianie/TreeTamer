#pragma once
#include "../TreeTamer/TreeTamer.h"
#include "tinyxml2.h"
#include <string>
#include <vector>
#include <stdexcept>

namespace TreeTamerTinyXml2
{
    template<typename stringType = std::wstring>
    class TreeTamerXmlPath
    {
        const std::vector<stringType> path;
    public:
        TreeTamerXmlPath(std::vector<stringType> path) : path(path) {}
        TreeTamerXmlPath(TreeTamerXmlPath&& other) : path(std::move(other.path)) {}
        TreeTamerXmlPath(const TreeTamerXmlPath& other) : path(other.path) {}
        bool operator==(const TreeTamerXmlPath& other) const
        {
            return path == other.path;
        }
        bool startsWith(const TreeTamerXmlPath& other) const
        {
            if (other.path.size() > path.size())
                return false;
            for (size_t i = 0; i < other.path.size(); ++i)
            {
                if (path[i] != other.path[i])
                    return false;
            }
            return true;
        }
        size_t getLength() const
        {
            return path.size();
        }
    };

    class TreeTamerXmlIterator
    {
        tinyxml2::XMLElement* current;
        tinyxml2::XMLElement* parentElement;
        int depth;
    public:
        TreeTamerXmlIterator(tinyxml2::XMLElement* root)
            : current(root), parentElement(nullptr), depth(0) {}

        bool hasNext()
        {
            return current != nullptr;
        }

        void nextSibling()
        {
            if (current != nullptr)
                current = current->NextSiblingElement();
        }

        bool hasChildren()
        {
            return current != nullptr && current->FirstChildElement() != nullptr;
        }

        int currentDepth()
        {
            return depth;
        }

        void firstChild()
        {
            if (current != nullptr)
            {
                parentElement = current;
                current = current->FirstChildElement();
                ++depth;
            }
        }

        void parent()
        {
            if (parentElement != nullptr)
            {
                current = parentElement;
                parentElement = nullptr; // Reset parentElement for simplicity
                --depth;
            }
            else
            {
                throw std::runtime_error("No parent available");
            }
        }

        bool hasParent()
        {
            return parentElement != nullptr;
        }

        const char* operator*()
        {
            return current != nullptr ? current->Name() : "";
        }
    };

    class TreeTamerTinyXml2 : TreeTamer::TreeTamer<std::string, tinyxml2::XMLDocument, TreeTamerXmlIterator, TreeTamerXmlPath<>>
    {

    };
}
