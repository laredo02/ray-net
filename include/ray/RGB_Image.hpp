
#ifndef __HEADER_RGB_IMAGE__
#define __HEADER_RGB_IMAGE__

#include <iostream>
#include <vector>
#include <random>

template<typename T> class RGB_Image {
public:

	RGB_Image(size_t w, size_t h);

	//void resize(size_t w, size_t h, T r, T g, T b);
	void resize(size_t w, size_t h, T r=static_cast<T>(0), T g=static_cast<T>(0), T b=static_cast<T>(0));
	void fill(T r, T g, T b);
	void randFill();
	void setPixel(size_t x, size_t y, T r, T g, T b);

	const std::vector<std::vector<T>>& getRedChannel() const;
	const std::vector<std::vector<T>>& getGreenChannel() const;
	const std::vector<std::vector<T>>& getBlueChannel() const;

	T getRedChannelPixel(size_t x, size_t y) const;
	T getGreenChannelPixel(size_t x, size_t y) const;
	T getBlueChannelPixel(size_t x, size_t y) const;

	size_t width() const;
	size_t height() const;

private:

	std::vector<std::vector<T>> m_RedChannel;
	std::vector<std::vector<T>> m_GreenChannel;
	std::vector<std::vector<T>> m_BlueChannel;

	size_t m_Width;
	size_t m_Height;

};

template<typename T> RGB_Image<T>::RGB_Image(size_t w, size_t h) : m_Width(w), m_Height(h)
{
	m_RedChannel.resize(w, std::vector<T>(h, 0));
	m_GreenChannel.resize(w, std::vector<T>(h, 0));
	m_BlueChannel.resize(w, std::vector<T>(h, 0));
}

template<typename T> void RGB_Image<T>::resize(size_t w, size_t h, T r, T g, T b)
{
	m_RedChannel.resize(w, std::vector<T>(h, r));
	m_GreenChannel.resize(w, std::vector<T>(h, g));
	m_BlueChannel.resize(w, std::vector<T>(h, b));
	m_Width = w;
	m_Height = h;
}

template<typename T> void RGB_Image<T>::fill(T r, T g, T b)
{
	for (size_t i=0; i<m_Width; i++) {
		for (size_t j=0; j<m_Width; j++) {
			m_RedChannel.at(i).at(j) = r;
			m_GreenChannel.at(i).at(j) = g;
			m_BlueChannel.at(i).at(j) = b;
		}
	}
}

template<typename T> void RGB_Image<T>::randFill()
{
	std::random_device rd;
	std::mt19937 gen { rd() };
	std::uniform_real_distribution<> distrib(0.0, 256.0);
	for (size_t i=0; i<m_Width; i++) {
		for (size_t j=0; j<m_Width; j++) {
			m_RedChannel.at(i).at(j) = static_cast<T>(distrib(gen));
			m_GreenChannel.at(i).at(j) = static_cast<T>(distrib(gen));
			m_BlueChannel.at(i).at(j) = static_cast<T>(distrib(gen));
		}
	}
}

template<typename T> void RGB_Image<T>::setPixel(size_t x, size_t y, T r, T g, T b) 
{
	m_RedChannel.at(x).at(y) = r;
	m_RedChannel.at(x).at(y) = g;
	m_RedChannel.at(x).at(y) = b;
}

template <typename T> const std::vector<std::vector<T>>& RGB_Image<T>::getRedChannel() const
{
	return m_RedChannel;
}

template <typename T> const std::vector<std::vector<T>>& RGB_Image<T>::getGreenChannel() const
{
	return m_RedChannel;
}

template <typename T> const std::vector<std::vector<T>>& RGB_Image<T>::getBlueChannel() const
{
	return m_RedChannel;
}

template <typename T> inline T RGB_Image<T>::getRedChannelPixel(size_t x, size_t y) const
{
	return m_RedChannel.at(x).at(y);
}

template <typename T> inline T RGB_Image<T>::getGreenChannelPixel(size_t x, size_t y) const
{
	return m_GreenChannel.at(x).at(y);
}

template <typename T> inline T RGB_Image<T>::getBlueChannelPixel(size_t x, size_t y) const
{
	return m_BlueChannel.at(x).at(y);
}

template <typename T> inline size_t RGB_Image<T>::width() const
{
	return m_Width;
}

template <typename T> inline size_t RGB_Image<T>::height() const
{
	return m_Height;
}

template <typename T> inline std::ostream& operator<<(std::ostream& os, const RGB_Image<T>& image) {
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

#endif // __HEADER_RGB_IMAGE__










