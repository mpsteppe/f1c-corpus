char __thiscall sub_526410(int this)
{
  float **v2; // eax
  int v3; // esi
  float *v4; // ecx
  int v5; // eax
  float **v6; // eax

  v2 = *(float ***)(this + 1744);
  v3 = this + 1744;
  *(_DWORD *)(this + 1752) = v2;
  if ( v2 )
  {
    v4 = *v2;
    if ( *v2 )
    {
      while ( fabs(*v4 - *(float *)(this + 2892852)) <= 2.0 )
      {
        if ( !((unsigned __int8 (__thiscall *)(int, float *, int))&dword_525828[30])(v3, v4, 1) )
          goto LABEL_7;
        *(_BYTE *)(this + 1760) = 1;
LABEL_9:
        v6 = *(float ***)(v3 + 8);
        if ( v6 )
        {
          v4 = *v6;
          if ( *v6 )
            continue;
        }
        return 1;
      }
      if ( *v4 > (double)*(float *)(this + 2892852) )
        return 1;
LABEL_7:
      v5 = *(_DWORD *)(v3 + 8);
      if ( v5 )
        *(_DWORD *)(v3 + 8) = *(_DWORD *)(v5 + 4);
      goto LABEL_9;
    }
  }
  return 1;
}
