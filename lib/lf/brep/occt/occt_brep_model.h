/**
 * @file
 * @brief Defines the OcctBrepModel class
 * @author Raffael Casagrande
 * @date   2020-11-06 05:18:16
 * @copyright MIT License
 */

#ifndef __c22f41716f574518a166a992467c0172
#define __c22f41716f574518a166a992467c0172

#include <Bnd_OBB.hxx>
#include <Geom_Curve.hxx>
#include <TopoDS_Shape.hxx>

#include "lf/brep/interface/interface.h"

#include <Geom_Surface.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Face.hxx>

#include "occt_brep_curve.h"
#include "occt_brep_surface.h"

namespace lf::brep::occt {

class OcctBrepModel : public interface::BrepModel {
 public:
  explicit OcctBrepModel(std::string_view filename);

  [[nodiscard]] std::vector<std::pair<interface::BrepCurve const *, double>>
  FindCurves(const Eigen::Vector3d &global) const override;

  [[nodiscard]] std::vector<
      std::pair<interface::BrepCurve const *, Eigen::RowVectorXd>>
  FindCurvesMulti(const Eigen::Matrix3Xd &global) const override;

  [[nodiscard]] std::vector<
      std::pair<interface::BrepSurface const *, Eigen::Vector2d>>
  FindSurfaces(const Eigen::Vector3d &global) const override;

  [[nodiscard]] std::vector<
      std::pair<interface::BrepSurface const *, Eigen::Matrix2Xd>>
  FindSurfacesMulti(const Eigen::Matrix3Xd &global) const override;

  [[nodiscard]] base::size_type NumCurves() const override {
    return edges_.size();
  }
  [[nodiscard]] base::size_type NumSurfaces() const override {
    return faces_.size();
  }

 private:
  TopoDS_Shape shape_;
  std::vector<OcctBrepCurve> edges_;
  std::vector<OcctBrepSurface> faces_;
};

}  // namespace lf::brep::occt

#endif  // __c22f41716f574518a166a992467c0172