/*
 * Copyright (c) 2019 Analog Devices Inc.
 *
 * This file is part of libm2k
 * (see http://www.github.com/analogdevicesinc/libm2k).
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef DEVICEOUT_HPP
#define DEVICEOUT_HPP
#include <iio.h>
#include <string>
#include <iostream>
#include <vector>
#include <functional>
#include <memory>
#include <libm2k/m2kglobal.hpp>
#include <libm2k/utils/devicegeneric.hpp>
#include <libm2k/enums.hpp>

using namespace std;

namespace libm2k {
namespace utils {
class Channel;
class Buffer;

class DeviceOut : public DeviceGeneric
{
public:
	DeviceOut(struct iio_context* context, std::string dev_name = "");
	virtual ~DeviceOut();

	virtual void initializeBuffer(unsigned int size, bool cyclic);
	virtual void push(std::vector<short> const &data, unsigned int channel,
		bool cyclic = true, bool multiplex = false);
	virtual void push(std::vector<unsigned short> const &data, unsigned int channel,
		bool cyclic = true, bool multiplex = false);
	virtual void push(unsigned short *data, unsigned int channel, unsigned int nb_samples,
		  bool cyclic = true, bool multiplex = false);
	virtual void push(std::vector<double> const &data, unsigned int channel, bool cyclic = true);
	virtual void push(double *data, unsigned int channel, unsigned int nb_samples, bool cyclic = true);
	virtual void push(short *data, unsigned int channel, unsigned int nb_samples, bool cyclic = true);
	virtual void stop();
	virtual void setKernelBuffersCount(unsigned int count);
	virtual struct IIO_OBJECTS getIioObjects();

private:
	class DeviceOutImpl;
	std::unique_ptr<DeviceOutImpl> m_pimpl;
};
}
}


#endif //DEVICE_HPP
