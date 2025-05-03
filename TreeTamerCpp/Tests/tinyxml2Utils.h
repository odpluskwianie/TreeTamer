#pragma once
#include "tinyxml2.h"
#include <iostream>
#include <string>

// Helper function to escape JSON special characters
std::string escapeJson(const std::string& str) {
    std::string escaped;
    for (char c : str) {
        switch (c) {
            case '\"': escaped += "\\\""; break;
            case '\\': escaped += "\\\\"; break;
            case '\b': escaped += "\\b"; break;
            case '\f': escaped += "\\f"; break;
            case '\n': escaped += "\\n"; break;
            case '\r': escaped += "\\r"; break;
            case '\t': escaped += "\\t"; break;
            default: escaped += c; break;
        }
    }
    return escaped;
}

// Function to print XML tree as JSON
void printXmlAsJson(tinyxml2::XMLElement* element, int level = 0) {
    if (!element) return;

    // Print indentation
    for (int i = 0; i < level; ++i) {
        std::cout << "  ";
    }

    // Print element name
    std::cout << "\"" << escapeJson(element->Name()) << "\": ";

    // Check if the element has children
    tinyxml2::XMLElement* child = element->FirstChildElement();
    if (child) {
        std::cout << "{" << std::endl;

        // Print attributes as JSON key-value pairs
        const tinyxml2::XMLAttribute* attribute = element->FirstAttribute();
        while (attribute) {
            for (int i = 0; i < level + 1; ++i) {
                std::cout << "  ";
            }
            std::cout << "\"" << escapeJson(attribute->Name()) << "\": "
                      << "\"" << escapeJson(attribute->Value()) << "\","
                      << std::endl;
            attribute = attribute->Next();
        }

        // Print child elements recursively
        while (child) {
            printXmlAsJson(child, level + 1);
            child = child->NextSiblingElement();
            if (child) std::cout << ","; // Add a comma between siblings
            std::cout << std::endl;
        }

        for (int i = 0; i < level; ++i) {
            std::cout << "  ";
        }
        std::cout << "}";
    } else {
        // Print attributes and text for leaf nodes
        std::cout << "{";

        const tinyxml2::XMLAttribute* attribute = element->FirstAttribute();
        bool hasAttributes = false;
        while (attribute) {
            hasAttributes = true;
            std::cout << "\"" << escapeJson(attribute->Name()) << "\": "
                      << "\"" << escapeJson(attribute->Value()) << "\", ";
            attribute = attribute->Next();
        }

        if (element->GetText()) {
            if (hasAttributes) std::cout << "\"text\": ";
            std::cout << "\"" << escapeJson(element->GetText()) << "\"";
        }

        std::cout << "}";
    }
}