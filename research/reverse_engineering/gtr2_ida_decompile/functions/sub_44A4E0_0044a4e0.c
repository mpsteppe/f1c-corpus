char __thiscall sub_44A4E0(int this)
{
  unsigned __int64 v2; // rax
  int v3; // edi
  double v4; // st7
  char *v5; // eax
  char Buffer[128]; // [esp+1Ch] [ebp-80h] BYREF

  LOBYTE(v2) = *(_BYTE *)(this + 6240);
  if ( (_BYTE)v2 )
  {
    v2 = (unsigned __int64)((double)(*(_DWORD *)(this + 6192) - 1) * flt_B6B960);
    v3 = v2;
    if ( *(_DWORD *)(this + 6196) != (_DWORD)v2 )
    {
      sub_4731E0(&dword_B6CB98);
      *(_DWORD *)(this + 6196) = v3;
      v4 = (double)*(int *)(this + 6196) * *(double *)(this + 6184) + *(double *)(this + 6176);
      *(double *)(this + 6168) = v4;
      v5 = sub_41D840(&byte_91CC38, "BRAKE BIAS");
      sprintf(Buffer, "%s %4.1f:%4.1f", v5, 100.0 - v4 * 100.0, v4 * 100.0);
      LOBYTE(v2) = sub_4730C0(Buffer, 3, &byte_1020304, 1084227584);
    }
  }
  return v2;
}
