int __thiscall sub_4E0C90(int this, float a2)
{
  int result; // eax
  int v4; // [esp+4h] [ebp-Ch] BYREF
  int v5; // [esp+8h] [ebp-8h] BYREF
  int v6; // [esp+Ch] [ebp-4h] BYREF

  if ( *(_DWORD *)(this + 2196) )
  {
    sub_54B420(&v4, &v5, &v6);
    *(float *)&v4 = *(float *)(this + 2352) - a2 * 0.2;
    return sub_54B4D0(v4, v5, v6, 0.0, 0.0, a2);
  }
  return result;
}
