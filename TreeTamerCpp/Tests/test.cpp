#include "pch.h"

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/foreach.hpp>
#include <string>
#include <set>
#include <exception>
#include <iostream>

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

std::string indent(int level) {
    std::string s;
    for (int i = 0; i < level; i++) s += "  ";
    return s;
}

void printTree(boost::property_tree::ptree& pt, int level) {///TO REMOVE
    if (pt.empty()) {
        std::cerr << "\"" << pt.data() << "\"";
    }

    else {
        if (level) std::cerr << std::endl;

        std::cerr << indent(level) << "{" << std::endl;

        for (boost::property_tree::ptree::iterator pos = pt.begin(); pos != pt.end();) {
            std::cerr << indent(level + 1) << "\"" << pos->first << "\": ";

            printTree(pos->second, level + 1);
            ++pos;
            if (pos != pt.end()) {
                std::cerr << ",";
            }
            std::cerr << std::endl;
        }
    }
}

TEST(XmlParserWork, OpenXml) {
	namespace pt = boost::property_tree;
    pt::ptree tree;
    pt::read_xml("some.xml", tree);
    std::string m_file = tree.get<std::string>("debug.filename");   
	printTree(tree, 0);
;
	EXPECT_NE(1, 0);
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}
