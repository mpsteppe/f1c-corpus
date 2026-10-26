void __thiscall sub_424CD0(int *this, int a2, int a3)
{
  bool v4; // al
  int v5; // edi
  int v6; // ecx
  int v7; // eax
  _DWORD *v8; // edx
  bool v9; // cc

  switch ( a2 )
  {
    case 4:
      sub_4A46F0(this, 1, 1);
      break;
    case 5:
      *((_BYTE *)this + 17736) = 0;
      sub_4A46F0(this, 0, 0);
      break;
    case 1:
      *((float *)this + 4175) = dbl_8AFEA0 + 2.0;
      break;
    case 15:
      if ( dword_7C56A4 == 7 )
        v4 = *(_DWORD *)(*this + 16484) == 0;
      else
        v4 = dword_7C56A8 != 8;
      if ( v4 )
      {
        if ( !*((_BYTE *)this + 17424) )
          SessionCleanupFlagClear(this);
      }
      else
      {
        SceneRenderUpdate(0);
        StateChangeNotify(0);
      }
      this[4433] = 0;
      ParameterValueSetter(18);
      this[4436] = 1;
      *((_BYTE *)this + 17736) = 1;
      break;
  }
  v5 = this[4394];
  if ( v5 )
  {
    v6 = this[4396];
    v7 = 0;
    if ( v6 < 0 )
    {
LABEL_21:
      v9 = v6 + 1 < this[4395];
      this[4396] = v6 + 1;
      if ( v9 )
      {
        *(_DWORD *)(v5 + 8 * (v6 + 1)) = a2;
        *(_DWORD *)(this[4394] + 8 * this[4396] + 4) = a3;
        CommandQueueResponseHandler(this);
        this[4396] = -1;
        if ( !a2 && this[4121] == 2 )
          *((_BYTE *)this + 17908) = 0;
      }
      else
      {
        this[4396] = v6;
      }
    }
    else
    {
      v8 = (_DWORD *)this[4394];
      while ( *v8 != a2 )
      {
        ++v7;
        v8 += 2;
        if ( v7 > v6 )
          goto LABEL_21;
      }
    }
  }
}
