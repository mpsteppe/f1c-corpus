void __thiscall sub_4A2CF0(int *this)
{
  float *v2; // edi
  int v3; // ebx
  double v4; // st7
  double v5; // st5

  v2 = (float *)(*(int (__thiscall **)(int *))(*this + 172))(this);
  if ( v2 )
  {
    v3 = (*(int (__thiscall **)(int *))(*this + 12))(this);
    v4 = (double)(v3 - (*(int (__thiscall **)(int *))(*this + 4))(this));
    if ( v4 > 5.0 )
    {
      v5 = (double)this[67] / v4 * (*((float *)this + 73) - *((float *)this + 72)) + *((float *)this + 72);
      if ( *((_BYTE *)this + 284) )
        *(_DWORD *)v2 = (__int64)(v5 + 0.5);
      else
        *v2 = v5;
    }
  }
}
