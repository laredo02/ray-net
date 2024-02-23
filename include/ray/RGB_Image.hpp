
#ifndef __HEADER_RGB_IMAGE__
#define __HEADER_RGB_IMAGE__

#include <vector>

class RGBAImage {
public:
	RGBAImage(uint32_t w, uint32_t h);
	void resize(uint32_t w, uint32_t h);
	void fill(uint8_t r, uint8_t g, uint8_t b);
	void setPixel(uint32_t x, uint32_t y, uint8_t r, uint8_t g, uint8_t b);
	const std::vector<std::vector<uint8_t>>& getRedChannel() const;
	const std::vector<std::vector<uint8_t>>& getGreenChannel() const;
	const std::vector<std::vector<uint8_t>>& getBlueChannel() const;
	uint8_t getRedChannelPixel(uint32_t x, uint32_t y) const;
	uint8_t getGreenChannelPixel(uint32_t x, uint32_t y) const;
	uint8_t getBlueChannelPixel(uint32_t x, uint32_t y) const;
	uint32_t width() const;
	uint32_t height() const;
private:
	std::vector<std::vector<uint8_t>> m_RedChannel;
	std::vector<std::vector<uint8_t>> m_GreenChannel;
	std::vector<std::vector<uint8_t>> m_BlueChannel;
	uint32_t m_Width;
	uint32_t m_Height;
};

#endif // __HEADER_RGB_IMAGE__








