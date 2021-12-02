#pragma once

class QAngle
{
public:
    QAngle(void)
    {
        Init();
    }
    QAngle(float X, float Y, float Z)
    {
        Init(X, Y, Z);
    }
    QAngle(const float* clr)
    {
        Init(clr[0], clr[1], clr[2]);
    }

    void Init(float ix = 0.0f, float iy = 0.0f, float iz = 0.0f)
    {
        x = ix;
        y = iy;
        z = iz;
    }

    float operator[](int i) const
    {
        return ((float*)this)[i];
    }
    float& operator[](int i)
    {
        return ((float*)this)[i];
    }

    QAngle& operator+=(const QAngle& v)
    {
        x += v.x; y += v.y; z += v.z;
        return *this;
    }
    QAngle& operator-=(const QAngle& v)
    {
        x -= v.x; y -= v.y; z -= v.z;
        return *this;
    }
    QAngle& operator*=(float fl)
    {
        x *= fl;
        y *= fl;
        z *= fl;
        return *this;
    }
    QAngle& operator*=(const QAngle& v)
    {
        x *= v.x;
        y *= v.y;
        z *= v.z;
        return *this;
    }
    QAngle& operator/=(const QAngle& v)
    {
        x /= v.x;
        y /= v.y;
        z /= v.z;
        return *this;
    }
    QAngle& operator+=(float fl)
    {
        x += fl;
        y += fl;
        z += fl;
        return *this;
    }
    QAngle& operator/=(float fl)
    {
        x /= fl;
        y /= fl;
        z /= fl;
        return *this;
    }
    QAngle& operator-=(float fl)
    {
        x -= fl;
        y -= fl;
        z -= fl;
        return *this;
    }

    QAngle& operator=(const QAngle &vOther)
    {
        x = vOther.x; y = vOther.y; z = vOther.z;
        return *this;
    }

    QAngle operator-(void) const
    {
        return QAngle(-x, -y, -z);
    }
    QAngle operator+(const QAngle& v) const
    {
        return QAngle(x + v.x, y + v.y, z + v.z);
    }
    QAngle operator-(const QAngle& v) const
    {
        return QAngle(x - v.x, y - v.y, z - v.z);
    }
    QAngle operator*(float fl) const
    {
        return QAngle(x * fl, y * fl, z * fl);
    }
    QAngle operator*(const QAngle& v) const
    {
        return QAngle(x * v.x, y * v.y, z * v.z);
    }
    QAngle operator/(float fl) const
    {
        return QAngle(x / fl, y / fl, z / fl);
    }
    QAngle operator/(const QAngle& v) const
    {
        return QAngle(x / v.x, y / v.y, z / v.z);
    }

    float Length() const
    {
        return sqrt(x*x + y*y + z*z);
    }
    float LengthSqr(void) const
    {
        return (x*x + y*y + z*z);
    }
    bool IsZero(float tolerance = 0.01f) const
    {
        return (x > -tolerance && x < tolerance &&
            y > -tolerance && y < tolerance &&
            z > -tolerance && z < tolerance);
    }

	float Normalize() const
	{
		QAngle res = *this;
		float l = res.Length();
		if (l != 0.0f)
		{
			res /= l;
		}
		else
		{
			res[0] = res[1] = res[2] = 0.0f;
		}
		return l;
	}

    float x;
    float y;
    float z;
};

inline QAngle operator*(float lhs, const QAngle& rhs)
{
    return rhs * lhs;
}
inline QAngle operator/(float lhs, const QAngle& rhs)
{
    return rhs / lhs;
}
