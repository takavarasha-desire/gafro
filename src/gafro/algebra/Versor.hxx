/*
    Copyright (c) 2022 Idiap Research Institute, http://www.idiap.ch/
    Written by Tobias Löw <https://tobiloew.ch>

    This file is part of gafro.

    gafro is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License version 3 as
    published by the Free Software Foundation.

    gafro is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with gafro. If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include <gafro/algebra/Versor.hpp>
#include <gafro/algebra/expressions/SandwichProduct.hpp>

namespace gafro
{

    template <class Derived, class T, int... index>
    Versor<Derived, T, index...>::Versor() = default;

    template <class Derived, class T, int... index>
    Versor<Derived, T, index...>::Versor(const Base &base) : Base(base)
    {}

    template <class Derived, class T, int... index>
    Versor<Derived, T, index...>::Versor(Base &&base) : Base(std::move(base))
    {}

    template <class Derived, class T, int... index>
    Versor<Derived, T, index...>::~Versor() = default;

    template <class Derived, class T, int... index>
    template <class Object>
    SandwichProduct<Object, Derived> Versor<Derived, T, index...>::apply(const Object &object) const
    {
        return SandwichProduct(*static_cast<const Object *>(&object), *static_cast<const Derived *>(this));
    }

}  // namespace gafro