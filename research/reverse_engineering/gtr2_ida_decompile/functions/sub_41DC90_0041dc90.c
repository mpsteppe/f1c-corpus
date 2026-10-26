void __thiscall sub_41DC90(int this)
{
  FILE *v2; // edi

  v2 = fopen("SDNDTG.DYN", "r");
  *(_DWORD *)(this + 52) = sub_41DA80();
  *(_DWORD *)(this + 56) = sub_41DA80();
  *(_DWORD *)(this + 68) = sub_41DB10();
  *(_DWORD *)(this + 72) = *(_DWORD *)(this + 68) + sub_41DB10();
  sub_41DBA0((float *)this);
  if ( v2 )
  {
    fclose(v2);
    *(_DWORD *)(this + 52) = 1000;
    *(_DWORD *)(this + 56) = 0;
    *(_DWORD *)(this + 68) = 1000;
    *(_DWORD *)(this + 72) = 1000;
    *(_DWORD *)(this + 60) = 1176256512;
  }
}
