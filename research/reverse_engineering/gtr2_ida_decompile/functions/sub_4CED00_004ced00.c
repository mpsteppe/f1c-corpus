int __thiscall sub_4CED00(float *this)
{
  int *v2; // edi
  int v3; // edi
  unsigned __int64 v4; // rax
  float v6; // edx
  float v7; // [esp+8h] [ebp-8h]
  float v8; // [esp+8h] [ebp-8h]

  v2 = (int *)(*(int (__thiscall **)(float *))(*(_DWORD *)this + 188))(this);
  v7 = this[74] - this[73];
  if ( v2 && v7 > 0.0 )
  {
    if ( *((_BYTE *)this + 288) )
    {
      v8 = ((double)*v2 - this[73]) / v7;
    }
    else
    {
      v8 = (*(float *)v2 - this[73]) / v7;
      if ( *(float *)v2 >= 0.0 && *(float *)v2 <= 1.0 )
        *(float *)v2 = (double)(int)(unsigned __int64)((*(float *)v2 + 0.0049999999) * 100.0) * 0.0099999998;
    }
    v3 = (*(int (__thiscall **)(float *))(*(_DWORD *)this + 12))(this);
    v4 = (unsigned __int64)((double)(v3 - (*(int (__thiscall **)(float *))(*(_DWORD *)this + 4))(this)) * v8 + 0.5);
    if ( (_DWORD)v4 != *((_DWORD *)this + 67) )
    {
      *((_DWORD *)this + 67) = v4;
      sub_4CDE30(this);
      (*(void (__thiscall **)(float *))(*(_DWORD *)this + 176))(this);
      return 0;
    }
  }
  else
  {
    v6 = *this;
    this[67] = 0.0;
    (*(void (__thiscall **)(float *, int))(LODWORD(v6) + 36))(this, 1);
  }
  (*(void (__thiscall **)(float *))(*(_DWORD *)this + 176))(this);
  return 0;
}
