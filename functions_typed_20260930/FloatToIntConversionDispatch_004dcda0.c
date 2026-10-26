int __thiscall sub_4DCDA0(_DWORD *this, float a2, float a3)
{
  int v4; // eax
  int v6; // [esp-4h] [ebp-8h]

  v6 = CRTFtol((double)dword_5D6D64 * a3);
  v4 = CRTFtol((double)dword_5D6D60 * a2);
  return TwoFieldSetterUpdate(this, v4, v6);
}

