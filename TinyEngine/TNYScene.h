#pragma once
#include <map>
#include <memory>
#include "TNYMATH.h"
#include "CoreEngine.h"
#include "CAM4DV1.h"
#include <mutex>
// 场景管理
class TNYScene
{
public:
	TNYScene(HWND hWnd)
	{
		initScene(hWnd);
	}
public:
	bool initScene(HWND hWnd) {
		if (m_device == nullptr)
		{
			m_device = std::unique_ptr<CoreEngine>(new CoreEngine(hWnd));
			m_device->init();
		}
		return true;
	}
	void SetCamera(int cam_attr, TNYMATH::POINT4D_PTR cam_pos,
		TNYMATH::VECTOR4D_PTR cam_dir, TNYMATH::POINT4D_PTR cam_target,
		float near_clip_z, float far_clip_z, float fov, float vp_width, float vp_height)
	{
		m_cam.Init_CAM4DV1(cam_attr, cam_pos, cam_dir, cam_target, 
			near_clip_z, far_clip_z, fov, vp_width, vp_height);

		m_device->installCam(&m_cam);
	}
	void DrawScene(int objid = -1)
	{
		m_device->Clear(0xff000000);
		if (objid == -1)
		{
			auto ita = m_mpObject.begin();
			while (ita != m_mpObject.end())
			{
				m_device->DrawObject(ita->second);
				ita++;
			}
		}
		else
		{
			m_device->DrawObject(m_mpObject[objid]);
		}
		m_device->present();
	}

	void AddObject(const TNYMATH::OBJECT4DV1* obj)
	{
		m_lock.lock();
		m_mpObject.insert(std::make_pair(obj->id, const_cast<TNYMATH::OBJECT4DV1*>(obj)));
		m_lock.unlock();
	}
	int GetWidth() {
		return m_device->m_width;
	}
	int GetHeight() {
		return m_device->m_heigth;
	}
private:
	std::map<unsigned int, TNYMATH::OBJECT4DV1*> m_mpObject;
	// render engine
	std::unique_ptr<CoreEngine> m_device = nullptr;
	// 相机管理 
	CAM4DV1 m_cam;

	std::mutex m_lock;
};

