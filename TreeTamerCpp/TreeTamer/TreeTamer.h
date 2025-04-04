#pragma once

namespace TreeTamer
{
	class TreeTamerBase
	{
	public:
		TreeTamerBase() = default;
		virtual ~TreeTamerBase() = default;
		virtual void processTree() = 0;
	};
}