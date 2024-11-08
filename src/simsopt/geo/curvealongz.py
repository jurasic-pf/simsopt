from math import pi
from itertools import chain

import numpy as np
import jax.numpy as jnp
from scipy.fft import rfft

from .curve import Curve, JaxCurve
import simsoptpp as sopp


__all__ = ['CurveAlongZ',]


class CurveAlongZ(sopp.CurveAlongZ, Curve):

    r"""
    A class for representing a straight current along the z-axis. Useful for representing tokamak-like configurations or just adding a toroidal 1/r field to an existing configuratoin. 

    The quadrature points are placed at [0, 0, 10* tan(pi*(gamma+0.5*dgamma-0.5))]. 
    a linear spacing in quadratures thus tigtly packs the quadrature points near the origin, with large separation at 0 (-inf) and 1 (inf). 
    """

    def __init__(self, quadpoints):
        if isinstance(quadpoints, int):
            quadpoints = list(np.linspace(0, 1, quadpoints, endpoint=False))
        elif isinstance(quadpoints, np.ndarray):
            quadpoints = list(quadpoints)
        sopp.CurveAlongZ.__init__(self, quadpoints)
        Curve.__init__(self, dofs=[])

    def get_dofs(self):
        """
        This function returns the dofs associated to this object.
        """
        return np.asarray(sopp.CurveXYZFourier.get_dofs(self))

    def set_dofs(self, dofs):
        """
        This function sets the dofs associated to this object.
        """
        self.local_x = dofs
        sopp.CurveXYZFourier.set_dofs(self, dofs)
