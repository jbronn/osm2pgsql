/*
#-----------------------------------------------------------------------------
# Part of osm2pgsql utility
#-----------------------------------------------------------------------------
# By Artem Pavlenko, Copyright 2007
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation; either version 2
# of the License, or (at your option) any later version.
# 
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
#-----------------------------------------------------------------------------
*/

#ifndef BUILD_GEOMETRY_H
#define BUILD_GEOMETRY_H

#include "osmtypes.hpp"

#include <vector>
#include <string>
#include <boost/noncopyable.hpp>

struct build_geometry : public boost::noncopyable
{
    build_geometry();
    ~build_geometry();

    static int parse_wkt(const char * wkt, struct osmNode *** xnodes, int ** xcount, int * polygon);
    
    char *get_wkt_simple(struct osmNode *, int count, int polygon);
    size_t get_wkt_split(struct osmNode *, int count, int polygon, double split_at);
    
    char* get_wkt(size_t index);
    double get_area(size_t index);
    size_t build(osmid_t osm_id, struct osmNode **xnodes, int *xcount, int make_polygon, int enable_multi, double split_at);
    void clear_wkts();
    void set_exclude_broken_polygon(int exclude);

private:
    std::vector<std::string> wkts;
    std::vector<double> areas;
    
    int excludepoly;
};

#endif 