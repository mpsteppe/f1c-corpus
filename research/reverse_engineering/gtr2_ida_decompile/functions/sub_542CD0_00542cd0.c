bool __fastcall sub_542CD0(int a1)
{
  int v2; // [esp+0h] [ebp-4h] BYREF

  v2 = a1;
  if ( !*(_BYTE *)(a1 + 12112) )
    return 0;
  sub_5E8E20(2, &v2);
  return *(float *)&v2 < 1.0;
}
