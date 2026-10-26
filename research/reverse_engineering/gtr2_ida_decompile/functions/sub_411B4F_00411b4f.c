// positive sp value has been detected, the output may be wrong!
void __usercall sub_411B4F(int a1@<ecx>, int _ESI@<esi>)
{
  int v19; // ecx
  int v20; // [esp-Ch] [ebp-18h]
  int v21; // [esp-8h] [ebp-14h]
  BOOL v22; // [esp-4h] [ebp-10h] BYREF

  __asm { fnstsw  ax }
  if ( __SETP__(HIBYTE(_AX) & 5, 0) )
  {
    __asm
    {
      fld     dword ptr [esi+44h]
      fsub    st, st(1)
      fst     dword ptr [esi+44h]
    }
    *(float *)(_ESI + 68) = _ET1;
    __asm
    {
      fcomp   [esp+arg_4]
      fnstsw  ax
    }
    if ( !__SETP__(HIBYTE(_AX) & 5, 0) )
      *(_DWORD *)(_ESI + 68) = v20;
  }
  else
  {
    __asm
    {
      fld     st
      fadd    dword ptr [esi+44h]
      fst     dword ptr [esi+44h]
    }
    *(float *)(_ESI + 68) = _ET1;
    __asm
    {
      fcomp   [esp+arg_4]
      fnstsw  ax
    }
    if ( (_AX & 0x4100) == 0 )
      *(_DWORD *)(_ESI + 68) = v20;
  }
  __asm
  {
    fld     [esp+arg_8]
    fld     dword ptr [esi+48h]
    fucompp
    fnstsw  ax
  }
  if ( __SETP__(HIBYTE(_AX) & 0x44, 0) )
  {
    __asm
    {
      fld     dword ptr [esi+48h]
      fcomp   [esp+arg_8]
      fnstsw  ax
    }
    if ( __SETP__(HIBYTE(_AX) & 5, 0) )
    {
      __asm
      {
        fld     dword ptr [esi+48h]
        fsub    st, st(1)
        fst     dword ptr [esi+48h]
      }
      *(float *)(_ESI + 72) = _ET1;
      __asm
      {
        fcomp   [esp+arg_8]
        fnstsw  ax
      }
      if ( !__SETP__(HIBYTE(_AX) & 5, 0) )
        *(_DWORD *)(_ESI + 72) = v21;
    }
    else
    {
      __asm
      {
        fld     st
        fadd    dword ptr [esi+48h]
        fst     dword ptr [esi+48h]
      }
      *(float *)(_ESI + 72) = _ET1;
      __asm
      {
        fcomp   [esp+arg_8]
        fnstsw  ax
      }
      if ( (_AX & 0x4100) == 0 )
        *(_DWORD *)(_ESI + 72) = v21;
    }
  }
  __asm
  {
    fld     [esp+arg_C]
    fld     dword ptr [esi+4Ch]
    fucompp
    fnstsw  ax
  }
  if ( __SETP__(HIBYTE(_AX) & 0x44, 0) )
  {
    __asm
    {
      fld     dword ptr [esi+4Ch]
      fcomp   [esp+arg_C]
      fnstsw  ax
    }
    if ( __SETP__(HIBYTE(_AX) & 5, 0) )
    {
      __asm
      {
        fsubr   dword ptr [esi+4Ch]
        fst     dword ptr [esi+4Ch]
      }
      *(float *)(_ESI + 76) = _ET1;
      __asm
      {
        fcomp   [esp+arg_C]
        fnstsw  ax
      }
      if ( !__SETP__(HIBYTE(_AX) & 5, 0) )
        *(_DWORD *)(_ESI + 76) = v22;
    }
    else
    {
      __asm
      {
        fadd    dword ptr [esi+4Ch]
        fst     dword ptr [esi+4Ch]
      }
      *(float *)(_ESI + 76) = _ET1;
      __asm
      {
        fcomp   [esp+arg_C]
        fnstsw  ax
      }
      if ( (_AX & 0x4100) == 0 )
        *(_DWORD *)(_ESI + 76) = v22;
    }
  }
  else
  {
    __asm { fstp    st }
  }
  if ( a1 >= 0 )
  {
    if ( a1 <= 2 )
    {
      if ( (byte_B722CC || byte_B722FC || a1 && a1 != 2)
        && dword_B6BF60
        && ((dword_B698E8 & 1) == 0 || (byte_B69A09 & 2) == 0)
        && !byte_B6F118
        && *(_DWORD *)(_ESI + 8) )
      {
        v22 = dword_B70E64 == 0;
        sub_4762A0(&v22);
        if ( dword_B70E64 )
        {
          sub_5E5190(1);
        }
        else
        {
          sub_5E5190(0);
          v19 = *(_DWORD *)(_ESI + 12);
          if ( v19 )
            sub_5E6F50(0, 0, *(_DWORD *)(v19 + 4), *(_DWORD *)(v19 + 8), -13421773);
        }
      }
    }
    else if ( a1 == 3 )
    {
      ((void (*)(void))off_16C9554)();
    }
  }
}
