
#ifndef IMAGE_H
#define IMAGE_H

#include "RayNet.h"
#include "XYZ.h"

template<typename T> class RGBImage {
public:

	RGBImage(size_t h, size_t w);
	//RGBImage(const RGBImage<T>& image);
	//RGBImage(RGBImage<T>&& image);
	
	
	void resize(size_t h, size_t w);
	void fill(T r, T g, T b);
	void randFill();
	void setPixel(size_t y, size_t x, XYZ<T> color);

	const std::vector<std::vector<T>>& getRedChannel() const;
	const std::vector<std::vector<T>>& getGreenChannel() const;
	const std::vector<std::vector<T>>& getBlueChannel() const;
	T getRedChannelPixel(size_t y, size_t x) const;
	T getGreenChannelPixel(size_t y, size_t x) const;
	T getBlueChannelPixel(size_t y, size_t x) const;
	
	size_t height() const;
	size_t width() const;
	
<<<<<<< HEAD
	void imageToTexture(SDL_Texture& texture);
=======
        void toTexture(SDL_Texture* texture) const;
>>>>>>> f96287a4f3044499e91ee54de919295923a298d3
	void saveToFile(const std::string& path) const;

private:

	std::vector<std::vector<T>> m_RedChannel;
	std::vector<std::vector<T>> m_GreenChannel;
	std::vector<std::vector<T>> m_BlueChannel;

	size_t m_Height;
	size_t m_Width;
};

using Image = RGBImage<double>;

template<typename T> RGBImage<T>::RGBImage(size_t h, size_t w) : m_Width(w), m_Height(h)
{
	m_RedChannel.resize(h, std::vector<T>(w, 0));
	m_GreenChannel.resize(h, std::vector<T>(w, 0));
	m_BlueChannel.resize(h, std::vector<T>(w, 0));
}

template<typename T> void RGBImage<T>::resize(size_t h, size_t w)
{
	m_RedChannel.resize(h, std::vector<T>(w, 0));
	m_GreenChannel.resize(h, std::vector<T>(w, 0));
	m_BlueChannel.resize(h, std::vector<T>(w, 0));
	m_Height = h;
	m_Width = w;
}

template<typename T> void RGBImage<T>::fill(T r, T g, T b)
{
	for (size_t i=0; i<m_Height; i++)
	{
		for (size_t j=0; j<m_Width; j++) {
			m_RedChannel.at(i).at(j) = r;
			m_GreenChannel.at(i).at(j) = g;
			m_BlueChannel.at(i).at(j) = b;
		}
	}
}

template<typename T> void RGBImage<T>::randFill()
{
	std::random_device rd;
	std::mt19937 gen { rd() };
	std::uniform_real_distribution<> distrib(0.0, 256.0);
	for (size_t i=0; i<m_Height; i++)
	{
		for (size_t j=0; j<m_Width; j++)
		{
			m_RedChannel.at(i).at(j) = static_cast<T>(distrib(gen));
			m_GreenChannel.at(i).at(j) = static_cast<T>(distrib(gen));
			m_BlueChannel.at(i).at(j) = static_cast<T>(distrib(gen));
		}
	}
}

template<typename T> void RGBImage<T>::setPixel(size_t y, size_t x, XYZ<T> color) 
{
	m_RedChannel.at(y).at(x) = color.x()*255.0;
	m_GreenChannel.at(y).at(x) = color.y()*255.0;
	m_BlueChannel.at(y).at(x) = color.z()*255.0;
}



template<typename T> const std::vector<std::vector<T>>& RGBImage<T>::getRedChannel() const
{
	return m_RedChannel;
}
template<typename T> const std::vector<std::vector<T>>& RGBImage<T>::getGreenChannel() const
{
	return m_GreenChannel;
}
template<typename T> const std::vector<std::vector<T>>& RGBImage<T>::getBlueChannel() const
{
	return m_BlueChannel;
}



template<typename T> inline T RGBImage<T>::getRedChannelPixel(size_t y, size_t x) const
{
	return m_RedChannel.at(y).at(x);
}
template<typename T> inline T RGBImage<T>::getGreenChannelPixel(size_t y, size_t x) const
{
	return m_GreenChannel.at(y).at(x);
}
template<typename T> inline T RGBImage<T>::getBlueChannelPixel(size_t y, size_t x) const
{
	return m_BlueChannel.at(y).at(x);
}



template<typename T> inline size_t RGBImage<T>::width() const
{
	return m_Width;
}

template<typename T> inline size_t RGBImage<T>::height() const
{
	return m_Height;
}

template<typename T> void RGBImage<T>::toTexture(SDL_Texture* texture) const {
    uint32_t* raw_data = nullptr;
    int width = static_cast<int>(m_Width);
    //if (SDL_QueryTexture(texture, nullptr, )) {
        if (SDL_LockTexture(texture, nullptr, (void **)&raw_data, &width)) {

            for (auto i=0; i<m_Width*m_Height; i++) {
                raw_data[i] = 0x00ffff00;
            }

            SDL_UpdateTexture(texture, nullptr, raw_data, width);
            SDL_UnlockTexture(texture);
        }
    //}
}

template<typename T> void RGBImage<T>::saveToFile(const std::string& path) const
{
	std::ofstream os { path, std::ios::out | std::ios::trunc };
	os << "P3\n" << m_Width << ' ' << m_Height << "\n255\n";
	for (size_t i{0}; i<m_Height; i++)
	{
		for (size_t j{0}; j<m_Width; j++)
		{
			os << static_cast<int>(m_RedChannel.at(i).at(j)) << ' '
			   << static_cast<int>(m_GreenChannel.at(i).at(j)) << ' '
			   << static_cast<int>(m_BlueChannel.at(i).at(j)) << '\n';
		}
	}
	os.close();
}

template<typename T> inline std::ostream& operator<<(std::ostream& os, const RGBImage<T>& image) {
	for (size_t i{0}; i<image.height(); i++)
	{
		for (size_t j{0}; j<image.width(); j++)
		{
			os << "[" << image.getRedChannelPixel(j, i) <<
				  ", " << image.getGreenChannelPixel(j, i) <<
				  ", " << image.getBlueChannelPixel(j, i) << "]"; 
		}
		os << '\n';
	}
	return os;
}

#endif /* IMAGE_H */

	