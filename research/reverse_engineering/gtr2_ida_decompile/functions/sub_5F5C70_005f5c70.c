void __thiscall sub_5F5C70(int this, int a2)
{
  int *v3; // edi
  int *v4; // ebx
  int v5; // edi
  int v6; // ebx

  if ( *(double *)(this + 8) != 0.0 )
  {
    v3 = (int *)(this + 40);
    v4 = (int *)(this + 44);
    sub_5F5760((double *)this, (LONG *)(this + 44), (DWORD *)(this + 40), 0);
    *(double *)(this + 24) = 0.0;
    v5 = *v3;
    v6 = *v4;
    *(_DWORD *)(this + 48) = v5;
    *(_DWORD *)(this + 52) = v6;
    *(_DWORD *)(this + 56) = 0;
    *(_DWORD *)(this + 60) = 0;
    if ( a2 )
    {
      *(_DWORD *)(this + 64) = v5;
      *(_DWORD *)(this + 68) = v6;
    }
    else
    {
      *(_DWORD *)(this + 64) = 0;
      *(_DWORD *)(this + 68) = 0;
    }
  }
}
