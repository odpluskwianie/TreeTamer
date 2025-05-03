#include "pch.h"
#include <string>
#include <set>
#include <exception>
#include <iostream>

#include "tinyxml2.h"
#include "tinyxml2Utils.h"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

std::string indent(int level) {
    std::string s;
    for (int i = 0; i < level; i++) s += "  ";
    return s;
}

TEST(XmlParserWorking, OpenXml) {
	tinyxml2::XMLDocument doc;
	FILE* fp = fopen("some.xml", "rb");
	doc.LoadFile(fp);
	if (doc.ErrorID() != tinyxml2::XML_SUCCESS) {
		std::cerr << "Error loading XML file: " << doc.ErrorID() << std::endl;
		return;
	}
	auto tree = doc.FirstChildElement();

	printXmlAsJson(tree, 0);
	std::cout << std::endl;

	EXPECT_NE(1, 0);
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}
