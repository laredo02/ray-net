
#include <iostream>
#include <cstdint>

#include "RGB_Image.hpp"

RGBAImage::RGBAImage(uint32_t w, uint32_t h) : m_Width(w), m_Height(h)
{
	m_RedChannel.resize(h, std::vector<uint8_t>(w, 0));
	m_GreenChannel.resize(h, std::vector<uint8_t>(w, 0));
	m_BlueChannel.resize(h, std::vector<uint8_t>(w, 0));
}

void RGBAImage::resize(uint32_t w, uint32_t h)
{
	m_RedChannel.resize(h, std::vector<uint8_t>(w, 0));
	m_GreenChannel.resize(h, std::vector<uint8_t>(w, 0));
	m_BlueChannel.resize(h, std::vector<uint8_t>(w, 0));
}

void RGBAImage::fill(uint8_t r, uint8_t g, uint8_t b)
{
	m_RedChannel.resize(m_Height, std::vector<uint8_t>(m_Width, r));
	m_GreenChannel.resize(m_Height, std::vector<uint8_t>(m_Width, g));
	m_BlueChannel.resize(m_Height, std::vector<uint8_t>(m_Width, b));
}

void RGBAImage::setPixel(uint32_t x, uint32_t y, uint8_t r, uint8_t g, uint8_t b)
{
	m_RedChannel.at(x).at(y) = r;
	m_RedChannel.at(x).at(y) = g;
	m_RedChannel.at(x).at(y) = b;
}

const std::vector<std::vector<uint8_t>>& RGBAImage::getRedChannel() const
{
	return m_RedChannel;
}

const std::vector<std::vector<uint8_t>>& RGBAImage::getGreenChannel() const
{
	return m_RedChannel;
}

const std::vector<std::vector<uint8_t>>& RGBAImage::getBlueChannel() const
{
	return m_RedChannel;
}

inline uint8_t RGBAImage::getRedChannelPixel(uint32_t x, uint32_t y) const
{
	return m_RedChannel.at(x).at(y);
}

inline uint8_t RGBAImage::getGreenChannelPixel(uint32_t x, uint32_t y) const
{
	return m_GreenChannel.at(x).at(y);
}

inline uint8_t RGBAImage::getBlueChannelPixel(uint32_t x, uint32_t y) const
{
	return m_BlueChannel.at(x).at(y);
}

inline uint32_t RGBAImage::width() const
{
	return m_Width;
}

inline uint32_t RGBAImage::height() const
{
	return m_Height;
}

std::ostream& operator<<(std::ostream& os, const RGBAImage& image) {
	for (uint32_t i=0; i<image.width(); i++) {
		for (uint32_t j=0; j<image.height(); j++) {
			os << "[" << image.getRedChannelPixel(i, j) <<
				  ", " << image.getGreenChannelPixel(i, j) <<
				  ", " << image.getBlueChannelPixel(i, j) << "]"; 
		}
		os << '\n';
	}
	return os;
}



