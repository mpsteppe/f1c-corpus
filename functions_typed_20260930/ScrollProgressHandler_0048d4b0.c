int __thiscall ScrollProgressHandler(float *this)
{
  int *v2; // ecx
  double v3; // st7
  int v4; // edi
  int v5; // edi
  float v7; // eax
  float v8; // [esp+8h] [ebp-8h]
  float v9; // [esp+8h] [ebp-8h]
  int v10; // [esp+Ch] [ebp-4h]

  v2 = (int *)(*(int (__thiscall **)(float *))(*(_DWORD *)this + 180))(this);
  v8 = this[62] - this[61];
  if ( v2 && v8 > 0.0 )
  {
    if ( *((_BYTE *)this + 240) )
      v3 = (double)*v2;
    else
      v3 = *(float *)v2;
    v9 = (v3 - this[61]) / v8;
    v4 = (*(int (__thiscall **)(float *))(*(_DWORD *)this + 32))(this);
    v10 = v4 - (*(int (__thiscall **)(float *))(*(_DWORD *)this + 24))(this);
    v5 = CRTFtol((double)v10 * v9 + 0.5);
    if ( v5 != *((_DWORD *)this + 56) )
    {
      (*(void (__thiscall **)(float *, int))(*(_DWORD *)this + 44))(this, 1);
      *((_DWORD *)this + 56) = v5;
      ShortComputation_8970(this);
      (*(void (__thiscall **)(float *))(*(_DWORD *)this + 176))(this);
      return 0;
    }
  }
  else
  {
    v7 = *this;
    this[56] = 0.0;
    (*(void (__thiscall **)(float *, int))(LODWORD(v7) + 56))(this, 1);
  }
  (*(void (__thiscall **)(float *))(*(_DWORD *)this + 176))(this);
  return 0;
}

