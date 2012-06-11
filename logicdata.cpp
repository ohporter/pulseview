/*
 * This file is part of the sigrok project.
 *
 * Copyright (C) 2012 Joel Holdsworth <joel@airwebreathe.org.uk>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA
 */

#include "logicdata.h"
#include "logicdatasnapshot.h"

using namespace boost;
using namespace std;

LogicData::LogicData(const sr_datafeed_meta_logic &meta) :
	SignalData(meta.samplerate),
	_num_probes(meta.num_probes)
{
}

int LogicData::get_num_probes() const
{
	return _num_probes;
}

void LogicData::push_snapshot(
	boost::shared_ptr<LogicDataSnapshot> &snapshot)
{
	_snapshots.push(snapshot);
}

queue< shared_ptr<LogicDataSnapshot> >& LogicData::get_snapshots()
{
	return _snapshots;
}