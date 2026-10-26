int __thiscall sub_50ADD0(int this, float a2)
{
  int result; // eax
  int v4; // ecx
  int v5; // [esp+8h] [ebp-Ch] BYREF
  int v6; // [esp+Ch] [ebp-8h] BYREF
  int v7; // [esp+10h] [ebp-4h] BYREF

  result = LODWORD(a2);
  v4 = *(_DWORD *)(this + 2528);
  *(float *)(this + 2872) = a2;
  if ( v4 )
  {
    sub_59E0C0(&v5, &v6, &v7);
    *(float *)&v5 = *(float *)(this + 2572) - a2 * 0.2;
    result = sub_59E170(v5, v6, v7, 0.0, 0.0, a2);
  }
  if ( *(_DWORD *)(this + 2532) )
  {
    sub_59E0C0(&v5, &v6, &v7);
    *(float *)&v5 = *(float *)(this + 2576) - a2 * 0.2;
    result = sub_59E170(v5, v6, v7, 0.0, 0.0, a2);
  }
  if ( *(_DWORD *)(this + 2536) )
  {
    sub_59E0C0(&v5, &v6, &v7);
    *(float *)&v5 = *(float *)(this + 2580) - a2 * 0.2;
    return sub_59E170(v5, v6, v7, 0.0, 0.0, a2);
  }
  return result;
}
