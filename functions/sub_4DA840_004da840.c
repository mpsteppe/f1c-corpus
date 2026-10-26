int __thiscall sub_4DA840(float *this)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int result; // eax
  int v6; // eax

  v2 = *((_DWORD *)this + 4);
  if ( !v2 )
  {
    *((_DWORD *)this + 4) = 2;
    v6 = sub_4D1B50((unsigned __int8 *)dword_8ACEE0, 0);
    if ( v6 >= 0 && v6 < dword_5C329C && !dword_5F073C[4656 * v6] )
    {
      *((_DWORD *)this + 4) = 1;
      this[6] = 2.0;
    }
    return 0;
  }
  v3 = v2 - 1;
  if ( !v3 )
  {
    if ( this[6] <= 0.0 )
    {
      result = 0;
      *((_DWORD *)this + 4) = 2;
      return result;
    }
    return 0;
  }
  if ( v3 != 1 )
    return 0;
  if ( !*((_DWORD *)this + 9) )
    *((_DWORD *)this + 9) = dword_5F0714[4656 * sub_4D1B50((unsigned __int8 *)dword_8ACEE0, 0)];
  if ( sub_4DAD80((int)this) )
    this[7] = 2.0;
  *((_DWORD *)this + 8) = sub_4DA990(this);
  if ( !sub_4DAE00((int)this) )
    return 0;
  if ( dword_7CE814
    || dword_5F073C[4656 * sub_4D1B50((unsigned __int8 *)dword_8ACEE0, 0)] != 1
    || !*(_DWORD *)(dword_7C54E8 + 16484) )
  {
    return 1;
  }
  SessionStateTransition((float *)(dword_7C54E8 + 12), (_DWORD *)1, 0);
  GameActionStateMachine(&dword_5EA510, 5, 1);
  v4 = sub_4D1B50((unsigned __int8 *)dword_8ACEE0, 0);
  GameStateDispatchChain(&dword_5EA510, v4);
  sub_4D8760(&dword_8AD298, 17, 0);
  return 0;
}
