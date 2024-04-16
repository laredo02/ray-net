
#pragma once

#include "RayNet.h"
#include "XYZ.h"

#if 1

template<typename T> class RGBImage {

public:

	RGBImage(size_t h, size_t w);
	//RGBImage(const RGBImage<T>& image);
	//RGBImage(RGBImage<T>&& image);


	void resize(size_t h, size_t w);
	void fill(T r, T g, T b);
	void randFill();
	void setPixel(size_t y, size_t x, XYZ<T> color);

	const std::vector<std::vector<T>>&getRedChannel() const;
	const std::vector<std::vector<T>>&getGreenChannel() const;
	const std::vector<std::vector<T>>&getBlueChannel() const;
	T getRedChannelPixel(size_t y, size_t x) const;
	T getGreenChannelPixel(size_t y, size_t x) const;
	T getBlueChannelPixel(size_t y, size_t x) const;

	size_t height() const;
	size_t width() const;


	void toTexture(SDL_Texture * const texture) const;
	void saveToFile(const std::string& path) const;

private:

	std::vector<std::vector<T>> m_RedChannel;
	std::vector<std::vector<T>> m_GreenChannel;
	std::vector<std::vector<T>> m_BlueChannel;

	size_t m_Height;
	size_t m_Width;
};

using Image=RGBImage<double>;

template<typename T> RGBImage<T>::RGBImage(size_t h, size_t w) : m_Width(w), m_Height(h) {
	m_RedChannel.resize(h, std::vector<T>(w, 0));
	m_GreenChannel.resize(h, std::vector<T>(w, 0));
	m_BlueChannel.resize(h, std::vector<T>(w, 0));
}

template<typename T> void RGBImage<T>::resize(size_t h, size_t w) {
	m_RedChannel.resize(h, std::vector<T>(w, 0));
	m_GreenChannel.resize(h, std::vector<T>(w, 0));
	m_BlueChannel.resize(h, std::vector<T>(w, 0));
	m_Height=h;
	m_Width=w;
}

template<typename T> void RGBImage<T>::fill(T r, T g, T b) {
	for (size_t i=0; i < m_Height; i++) {
		for (size_t j=0; j < m_Width; j++) {
			m_RedChannel.at(i).at(j)=r;
			m_GreenChannel.at(i).at(j)=g;
			m_BlueChannel.at(i).at(j)=b;
		}
	}
}

template<typename T> void RGBImage<T>::randFill() {
	std::random_device rd;
	std::mt19937 gen{ rd()};
	std::uniform_real_distribution<> distrib(0.0, 256.0);
	for (size_t i=0; i < m_Height; i++) {
		for (size_t j=0; j < m_Width; j++) {
			m_RedChannel.at(i).at(j)=static_cast<T> (distrib(gen));
			m_GreenChannel.at(i).at(j)=static_cast<T> (distrib(gen));
			m_BlueChannel.at(i).at(j)=static_cast<T> (distrib(gen));
		}
	}
}

template<typename T> void RGBImage<T>::setPixel(size_t y, size_t x, XYZ<T> color) {
	m_RedChannel.at(y).at(x)=color.x()*255.0;
	m_GreenChannel.at(y).at(x)=color.y()*255.0;
	m_BlueChannel.at(y).at(x)=color.z()*255.0;
}

template<typename T> const std::vector<std::vector<T>>&RGBImage<T>::getRedChannel() const {
	return m_RedChannel;
}

template<typename T> const std::vector<std::vector<T>>&RGBImage<T>::getGreenChannel() const {
	return m_GreenChannel;
}

template<typename T> const std::vector<std::vector<T>>&RGBImage<T>::getBlueChannel() const {
	return m_BlueChannel;
}

template<typename T> inline T RGBImage<T>::getRedChannelPixel(size_t y, size_t x) const {
	return m_RedChannel.at(y).at(x);
}

template<typename T> inline T RGBImage<T>::getGreenChannelPixel(size_t y, size_t x) const {
	return m_GreenChannel.at(y).at(x);
}

template<typename T> inline T RGBImage<T>::getBlueChannelPixel(size_t y, size_t x) const {
	return m_BlueChannel.at(y).at(x);
}

template<typename T> inline size_t RGBImage<T>::width() const {
	return m_Width;
}

template<typename T> inline size_t RGBImage<T>::height() const {
	return m_Height;
}

template<typename T> void RGBImage<T>::toTexture(SDL_Texture * const texture) const {
	Uint32 raw_data[m_Width * m_Height];
	int width=static_cast<int> (m_Width);

	for (int i=0; i < m_Height; i++) {
		for (int j=0; j < m_Width; j++) {

			Uint32 red=static_cast<Uint32> (m_RedChannel.at(i).at(j));
			Uint32 green=static_cast<Uint32> (m_GreenChannel.at(i).at(j));
			Uint32 blue=static_cast<Uint32> (m_BlueChannel.at(i).at(j));
#if ASSERTIONS == 1
			assert(0 <= red && red <= 255 && 0 <= green && green <= 255 && 0 <= blue && blue <= 255);
#endif
			Uint32 color=(0xff << 24) | (red << 16) | (green << 8) | blue;
			raw_data[i * m_Width + j]=color;
		}
	}

	SDL_UpdateTexture(texture, nullptr, raw_data, width * sizeof (Uint32));
}

template<typename T> void RGBImage<T>::saveToFile(const std::string& path) const {
	std::ofstream os{ path, std::ios::out | std::ios::trunc};
	os << "P3\n" << m_Width << ' ' << m_Height << "\n255\n";
	for (int i=0; i < m_Height; i++) {
		for (int j=0; j < m_Width; j++) {

			uint32_t red=static_cast<int> (m_RedChannel.at(i).at(j));
			uint32_t green=static_cast<int> (m_GreenChannel.at(i).at(j));
			uint32_t blue=static_cast<int> (m_BlueChannel.at(i).at(j));
#if ASSERTIONS == 1
			assert(0 <= red && red <= 255 && 0 <= green && green <= 255 && 0 <= blue && blue <= 255);
#endif
			os << red << ' ' << green << ' ' << blue << '\n';
		}
	}
	os.close();
}








#else

using namespace std;

class Image {

public:

	Image();
	Image(size_t h, size_t w);
	Image(const Image& image);
	Image(Image&& image) noexcept;
	Image& operator=(const Image& image);
	Image& operator=(Image&& image) noexcept;
	~Image();

	size_t height() const;
	size_t width() const;

	void resize(size_t h, size_t w);
	void fill(const Vector3& color);
	void randFill();

	void setPixel(size_t y, size_t x, const Vector3& color);
	const Vector3& getPixel(size_t y, size_t x) const;

	void saveToFile(const std::string& path) const;

private:

	Vector3* m_Data;

	size_t m_Height;
	size_t m_Width;

};

Image::Image() : m_Height(0), m_Width(0), m_Data(nullptr) {}

Image::Image(size_t h, size_t w) : m_Width(w), m_Height(h) {
	m_Data = new Vector3[m_Height*m_Width];
}

Image::Image(const Image& other) : m_Height(other.m_Height), m_Width(other.m_Width) {
	m_Data = new Vector3[m_Height*m_Width];
	for (int i=0; i<m_Height; i++) {
		for (int j=0; j<m_Width; j++) {
#if ASSERTIONS == 1
			assert(i*m_Width + j < m_Height*m_Width);
			assert(0 <= i && i <= m_Height);
			assert(0 <= j && j <= m_Width);
#endif
			m_Data[i*m_Width + j] = other.m_Data[i*m_Width + j];
		}
}
}

Image::Image(Image&& other) noexcept : m_Height(other.m_Height), m_Width(other.m_Width), m_Data(other.m_Data) {
	other.m_Height = 0;
	other.m_Width = 0;
	other.m_Data = nullptr;
}

Image& Image::operator=(const Image& other) {
	if (&other != this) {
		delete[] m_Data;

		m_Height = other.m_Height;
		m_Width = other.m_Width;

		m_Data = new Vector3[m_Height*m_Width];
		for (int i=0; i<m_Height; i++) {
			for (int j=0; j<m_Width; j++) {
#if ASSERTIONS == 1
			assert(i*m_Width + j < m_Height*m_Width);
			assert(0 <= i && i <= m_Height);
			assert(0 <= j && j <= m_Width);
#endif
				m_Data[i*m_Width + j] = other.m_Data[i*m_Width + j];
			}
		}

	}
	return *this;
}

Image& Image::operator=(Image&& other) noexcept {
	if (&other != this) {
		delete[] m_Data;

		m_Data = other.m_Data;
		m_Height = other.m_Height;
		m_Width = other.m_Width;

		other.m_Data = nullptr;
		other.m_Height = 0;
		other.m_Width = 0;
	}
	return *this;
}

Image::~Image() {
	delete[] m_Data;
}

void Image::resize(size_t height, size_t width) {
	delete[] m_Data;
	m_Height = height;
	m_Width = width;
	m_Data = new Vector3[m_Height*m_Width];
}

void Image::fill(const Vector3& color) {
	for (int i = 0; i < m_Height; i++) {
		for (int j = 0; j < m_Width; j++) {
#if ASSERTIONS == 1
			assert(i*m_Width + j < m_Height*m_Width);
			assert(0 <= i && i <= m_Height);
			assert(0 <= j && j <= m_Width);
#endif
			m_Data[i*m_Width + j] = color;
		}
	}
}

void Image::randFill() {

	std::random_device rd;
	std::mt19937 gen{ rd()};
	std::uniform_real_distribution<> distrib(0.0, 1.0);

	for (int i = 0; i < m_Height; i++) {
		for (int j = 0; j < m_Width; j++) {
#if ASSERTIONS == 1
			assert(i*m_Width + j < m_Height*m_Width);
			assert(0 <= i && i <= m_Height);
			assert(0 <= j && j <= m_Width);
#endif
			m_Data[i*m_Width + j] = Vector3{ distrib(gen), distrib(gen), distrib(gen) };
		}
	}

}

void Image::setPixel(size_t y, size_t x, const Vector3& color) {

#if ASSERTIONS == 1
	assert(y*m_Width + x < m_Height*m_Width);
	assert(0 <= y && y <= m_Height);
	assert(0 <= x && x <= m_Width);
	assert(0.0 <= color.red && color.red <= 1.0);
	assert(0.0 <= color.green && color.green <= 1.0);
	assert(0.0 <= color.blue && color.blue <= 1.0);
	assert(0.0 <= color.alpha && color.alpha <= 1.0);
#endif

	m_Data[y*m_Width + x] = color;

}

inline size_t Image::width() const { return m_Width; }
inline size_t Image::height() const { return m_Height; }

void Image::saveToFile(const std::string& path) const {
	std::ofstream os{ path, std::ios::out | std::ios::trunc};
	os << "P3\n" << m_Width << ' ' << m_Height << "\n255\n";
	for (int i=0; i < m_Height; i++) {
		for (int j=0; j < m_Width; j++) {
#if ASSERTIONS == 1
			assert(i*m_Width + j < m_Height*m_Width);
			assert(0 <= i && i <= m_Height);
			assert(0 <= j && j <= m_Width);
#endif
			int red = static_cast<int>(m_Data[i*m_Width + j].red*255.0);
			int green = static_cast<int>(m_Data[i*m_Width + j].green*255.0);
			int blue = static_cast<int>(m_Data[i*m_Width + j].blue*255.0);
#if ASSERTIONS == 1
			assert(0 <= red && red <= 255 && 0 <= green && green <= 255 && 0 <= blue && blue <= 255);
#endif
			os << red << ' ' << green << ' ' << blue << '\n';
		}
	}
	os.close();
}


#endif