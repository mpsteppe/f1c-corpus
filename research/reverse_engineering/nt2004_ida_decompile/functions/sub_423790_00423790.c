void __thiscall sub_423790(int this)
{
  int v1; // eax
  int v2; // edx
  int v3; // eax
  int v4; // eax

  if ( *(float *)(this + 18932) <= 0.0 )
  {
    v1 = *(_DWORD *)(this + 24020);
    v2 = *(_DWORD *)(this + 18912);
    if ( v1 == 3 || v1 == 1 )
    {
      if ( v2 != -1 )
        sub_51BFD0(-1);
    }
    else
    {
      if ( !v2 || v2 == -1 )
        goto LABEL_9;
      if ( *(float *)(this + 18940) >= (double)*(float *)(this + 18820) )
      {
        if ( v2 > 1 && *(float *)(this + 4 * v2 + 18944) > (double)*(float *)(this + 18820) )
        {
          v4 = *(_DWORD *)(this + 18912);
          if ( v4 > 0 )
            sub_51BFD0(v4 - 1);
        }
      }
      else if ( *(float *)(this + 18352) > 0.80000001 && *(float *)(this + 18600) > 0.80000001 )
      {
LABEL_9:
        v3 = *(_DWORD *)(this + 18912);
        if ( v3 < *(_DWORD *)(this + 18920) )
          sub_51BFD0(v3 + 1);
      }
    }
  }
}
