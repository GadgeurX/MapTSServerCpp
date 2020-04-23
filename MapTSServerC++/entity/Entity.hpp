#pragma once

#include <cstdint>
#include <boost/geometry/geometries/geometries.hpp>

namespace bg = boost::geometry;

typedef bg::model::point<int32_t, 2, bg::cs::cartesian> Point2D;
//typedef bg::model::polygon<point_t> polygon_t;
//typedef bg::model::multi_polygon<polygon_t> mpolygon_t;

class Entity {
private:
	std::uint32_t id;
	std::uint32_t life;
	std::uint32_t maxLife;

	std::uint32_t action;

	std::vector<std::uint32_t> targets;

	Point2D position;
};