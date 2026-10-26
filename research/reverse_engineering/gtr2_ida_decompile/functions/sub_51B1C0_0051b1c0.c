int __thiscall sub_51B1C0(_DWORD *this, float *a2, float *a3)
{
  this[1] = (unsigned __int64)(*a2 * 100.0) & 0xFFF
          | ((((unsigned int)(unsigned __int64)(a2[2] * 100.0) << 8)
            | (unsigned __int8)(unsigned __int64)((a2[1] - 1.0) * 100.0)) << 12);
  return sub_51A520(this + 2, a3);
}
