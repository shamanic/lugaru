/*
Copyright (C) 2010-2016 - Lugaru contributors (see AUTHORS file)

This file is part of Lugaru.

Lugaru is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

Lugaru is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Lugaru.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef ANIMATION_H
#define ANIMATION_H

enum anim_attack_type {
    neutral, normalattack, reversed, reversal
};

enum anim_height_type {
    lowheight, middleheight, highheight
};

enum animation_types {
#define DECLARE_ANIM(id, ...) id,
#include "Animation.def"
#undef DECLARE_ANIM
    animation_count
};

enum animation_bit_offsets {
#define DECLARE_ANIM_BIT(bit) o_##bit,
#include "Animation.def"
#undef DECLARE_ANIM_BIT
    animation_bit_count
};

enum animation_bits_def {
#define DECLARE_ANIM_BIT(bit) bit = 1 << o_##bit,
#include "Animation.def"
#undef DECLARE_ANIM_BIT
};

static const int animation_bits[animation_count] = {
#define DECLARE_ANIM(id, name, height, type, bits) bits,
#include "Animation.def"
#undef DECLARE_ANIM
};

extern Animation animation[animation_count];

extern void loadAllAnimations();
#endif
