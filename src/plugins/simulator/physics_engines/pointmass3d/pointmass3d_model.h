/**
 * @file <argos3/plugins/simulator/physics_engines/pointmass3d/pointmass3d_model.h>
 *
 * @author Carlo Pinciroli - <ilpincy@gmail.com>
 */

#ifndef POINTMASS3D_ENTITY_H
#define POINTMASS3D_ENTITY_H

namespace argos {
   class CPointMass3DEngine;
}

#include <argos3/core/simulator/physics_engine/physics_model.h>
#include <argos3/plugins/simulator/physics_engines/pointmass3d/pointmass3d_engine.h>
#include <argos3/core/utility/math/vector3.h>
#include <argos3/core/utility/math/quaternion.h>

namespace argos {

   class CPointMass3DModel : public CPhysicsModel {

   public:

      typedef std::map<std::string, CPointMass3DModel*> TMap;

   public:

      CPointMass3DModel(CPointMass3DEngine& c_engine,
                        CEmbodiedEntity& c_entity);

      virtual ~CPointMass3DModel() {}

      virtual void MoveTo(const CVector3& c_position,
                          const CQuaternion& c_orientation);

      virtual void Reset();

      virtual void Step() = 0;
      virtual void UpdateFromEntityStatus() = 0;

      virtual bool IsCollidingWithSomething() const {
         return false;
      }

      virtual bool CheckIntersectionWithRay(Real& f_t_on_ray,
                                            const CRay3& c_ray) const = 0;

      /**
       * Updates the origin anchor associated to the embodied entity.
       */
      void UpdateOriginAnchor(SAnchor& s_anchor);

   protected:

      CPointMass3DEngine& m_cPM3DEngine;

      /** The position of the model in this engine. */
      CVector3 m_cPosition;

      /** The linear velocity of this model in the engine. */
      CVector3 m_cVelocity;

      /** The acceleration of this model in the engine. */
      CVector3 m_cAcceleration;

   };

}

#endif