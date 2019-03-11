// This file is part of Bembel, the higher order C++ boundary element library.
// It was written as part of a cooperation of J. Doelz, H. Harbrecht, S. Kurz,
// M. Multerer, S. Schoeps, and F. Wolf at Technische Universtaet Darmstadt,
// Universitaet Basel, and Universita della Svizzera italiana, Lugano. This
// source code is subject to the GNU General Public License version 3 and
// provided WITHOUT ANY WARRANTY, see <http://www.bembel.eu> for further
// information.

#ifndef _geom_shape_
#define _geom_shape_

#include <fstream>
#include <iomanip>
#include <iostream>
#include "spline/patch.h"

namespace Spl {

/**
 * \brief Loads geometry from file with GEOPDE-format. Note that the direction
 * of the normals must be consistent
 *
 * \param[in]  name      Path to geometry file
 *
 * \return std::vector of NURBS::Patch describing geometry
 *
 */
std::vector<Patch> loadGeometryFile(std::string name);
/**
 * Method to making textfile for the geometry
 * [input] name - name of new textfile
 *         patchNr - number of all patches
 * [output] - void but makes txt file in folder
 **/
inline void makeFile(std::string name, int patchNr) {
  std::ofstream file;
  file.open(name);
  file << "# nurbs mesh v.2.1"
       << "\r\n";
  file << "# " << name << "\r\n";
  file << "# Generated by BEMBEL, see www.bembel.eu"
       << "\r\n";
  file << "#"
       << "\r\n";
  file << "2 3 " << patchNr << " 0 0 "
       << "\r\n";
  file.close();
}
/**
 * Method to write Patch information in Textfile
 *[input] knt1 -knotVector1
 *        knt2 -knotVector2
 *        tmp - Vector with x,y,z,w Matices
 *        name - filename
 *        patchNrCurr - current patch number
 *[output] - void but adds information in Textfile
 **/
void writePatch(std::string name, int patchNrCurr,
                std::vector<Eigen::MatrixXd> xyzw, std::vector<double> knt1,
                std::vector<double> knt2);
}  // namespace Spl

#endif