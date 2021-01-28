/**
 * @file
 * @brief Defines the OCCTSurfaceGeometry class
 * @author Raffael Casagrande
 * @date   2020-11-20 03:15:45
 * @copyright MIT License
 */

#ifndef __9b2aa16d069a447eaa411ed6c262f4f1
#define __9b2aa16d069a447eaa411ed6c262f4f1

#include <lf/brep/interface/interface.h>

#include <Bnd_OBB.hxx>
#include <Geom_Surface.hxx>
#include <TopoDS_Face.hxx>

namespace lf::brep::occt {

class OcctBrepSurface : public interface::BrepSurface {
 public:
  OcctBrepSurface(TopoDS_Face&& face);
  OcctBrepSurface(const OcctBrepSurface&) = default;
  OcctBrepSurface(OcctBrepSurface&&) = default;
  OcctBrepSurface& operator=(const OcctBrepSurface&) = default;
  OcctBrepSurface& operator=(OcctBrepSurface&&) = default;
  ~OcctBrepSurface() = default;

  [[nodiscard]] base::dim_t DimGlobal() const override { return 3; }
  [[nodiscard]] base::dim_t DimLocal() const override { return 2; }
  [[nodiscard]] Eigen::MatrixXd GlobalMulti(
      const Eigen::MatrixXd& local) const override;

  [[nodiscard]] Eigen::Vector3d Global(
      const Eigen::Vector2d& local) const override;
  [[nodiscard]] Eigen::MatrixXd JacobianMulti(
      const Eigen::MatrixXd& local) const override;

  [[nodiscard]] Eigen::Matrix<double, 3, 2> Jacobian(
      const Eigen::Vector2d& local) const override;
  [[nodiscard]] std::pair<double, Eigen::Vector2d> Project(
      const Eigen::Vector3d& global) const override;
  [[nodiscard]] std::vector<bool> IsInBoundingBoxMulti(
      const Eigen::MatrixXd& global) const override;

  [[nodiscard]] bool IsInBoundingBox(
      const Eigen::Vector3d& global) const override;
  [[nodiscard]] bool IsInside(const Eigen::Vector2d& local) const override;

  // OCCT specific member functions:

  [[nodiscard]] const TopoDS_Face& Face() const { return face_; }

 private:
  TopoDS_Face face_;
  Bnd_OBB obb_;
  opencascade::handle<Geom_Surface> surface_;
};

}  // namespace lf::brep::occt

#endif  // __9b2aa16d069a447eaa411ed6c262f4f1