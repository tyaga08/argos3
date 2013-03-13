/**
 * @file <argos3/plugins/simulator/physics_engines/dynamics2d/dynamics2d_box_model.h>
 *
 * @author Carlo Pinciroli - <ilpincy@gmail.com>
 */

#ifndef DYNAMICS2D_BOX_MODEL_H
#define DYNAMICS2D_BOX_MODEL_H

namespace argos {
   class CDynamics2DBoxModel;
}

#include <argos3/plugins/simulator/physics_engines/dynamics2d/dynamics2d_model.h>
#include <argos3/plugins/simulator/entities/box_entity.h>

namespace argos {

   class CDynamics2DBoxModel : public CDynamics2DModel {

   public:

      CDynamics2DBoxModel(CDynamics2DEngine& c_engine,
                          CBoxEntity& c_entity);
      virtual ~CDynamics2DBoxModel();

      virtual bool CheckIntersectionWithRay(Real& f_t_on_ray,
                                            const CRay3& c_ray) const;

      virtual bool MoveTo(const CVector3& c_position,
                          const CQuaternion& c_orientation,
                          bool b_check_only = false);

      virtual void Reset();

      virtual void CalculateBoundingBox();

      virtual void UpdateEntityStatus();
      virtual void UpdateFromEntityStatus() {}

      virtual bool IsCollidingWithSomething() const;

   private:

      CBoxEntity&   m_cBoxEntity;
      cpFloat       m_fMass;
      cpShape*      m_ptShape;
      cpBody*       m_ptBody;
      cpConstraint* m_ptLinearFriction;
      cpConstraint* m_ptAngularFriction;

   };

}

#endif