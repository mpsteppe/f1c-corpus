int __thiscall sub_40AD30(float *this, float a2)
{
  float v3; // edx
  int result; // eax
  int v5; // ecx

  v3 = *this;
  this[1] = a2;
  result = (*(int (**)(void))(LODWORD(v3) + 8))();
  if ( result )
  {
    v5 = *((_DWORD *)this + 3);
    if ( v5 )
    {
      if ( a2 == 0.0 )
        return (*(int (__thiscall **)(float *))(*(_DWORD *)this + 12))(this);
      else
        return AIL_set_stream_volume_levels(v5, *((_DWORD *)this + 1), *((_DWORD *)this + 1));
    }
  }
  return result;
}
