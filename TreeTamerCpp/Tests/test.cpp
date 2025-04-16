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

TEST(XmlParserWork, OpenXml) {
	namespace pt = boost::property_tree;
    // Create empty property tree object
    pt::ptree tree;

    // Parse the XML into the property tree.
    pt::read_xml("some.xml", tree);

    // Use the throwing version of get to find the debug filename.
    // If the path cannot be resolved, an exception is thrown.
    std::string m_file = tree.get<std::string>("debug.filename");

    // Use the default-value version of get to find the debug level.
    // Note that the default value is used to deduce the target type.
    //std:: = tree.get("debug.level", 0);

    // Use get_child to find the node containing the modules, and iterate over
    // its children. If the path cannot be resolved, get_child throws.
    // A C++11 for-range loop would also work.
    //BOOST_FOREACH(pt::ptree::value_type & v, tree.get_child("debug.modules")) {
    //    // The data function is used to access the data stored in a node.
    //    m_modules.insert(v.second.data());
    //}

	EXPECT_NE(1, 0);
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}
