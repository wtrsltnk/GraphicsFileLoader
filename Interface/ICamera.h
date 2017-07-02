#ifndef ICAMERA_H
#define ICAMERA_H

class ICamera
{
public: virtual	void		Setup() = 0;
public: virtual void		Move(float front, float right, float up) = 0;
public: virtual void		Rotate(float pitch, float roll, float yaw) = 0;
};

#endif