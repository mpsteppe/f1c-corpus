int __thiscall sub_486830(void *this)
{
  int v2; // ebp
  int v3; // esi
  int v4; // edi
  int v6; // [esp+10h] [ebp-14h]
  int v7; // [esp+14h] [ebp-10h] BYREF
  int v8; // [esp+18h] [ebp-Ch] BYREF
  int v9; // [esp+1Ch] [ebp-8h] BYREF
  int v10; // [esp+20h] [ebp-4h] BYREF

  (*(void (__thiscall **)(void *, int *, int *, int *, int *))(*(_DWORD *)this + 8))(this, &v8, &v10, &v7, &v9);
  v2 = v7;
  v6 = v8;
  v3 = v9 - v7;
  v4 = v10 - v8;
  if ( TimedAnimationTrigger((int)this) )
  {
    Accessor();
    if ( !(unsigned __int8)ShortComputation_1c70(v2, v6, v3, v4) )
      return 1;
  }
  Accessor();
  return (unsigned __int8)ShortComputation_1cb0(v2, v6, v3, v4) != 0 ? 2 : 0;
}
