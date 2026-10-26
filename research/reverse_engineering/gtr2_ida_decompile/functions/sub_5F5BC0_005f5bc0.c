void __thiscall sub_5F5BC0(int this)
{
  unsigned int v2; // ecx
  unsigned int v3; // edx
  unsigned int v4; // eax
  unsigned int v5; // [esp+4h] [ebp-20h] BYREF
  DWORD v6; // [esp+8h] [ebp-1Ch] BYREF
  unsigned __int64 v7; // [esp+18h] [ebp-Ch]
  DWORD v8; // [esp+20h] [ebp-4h]

  if ( *(double *)(this + 8) != 0.0 && (*(_DWORD *)(this + 68) || *(_DWORD *)(this + 64)) )
  {
    sub_5F5760((double *)this, (LONG *)&v5, &v6, 0);
    v2 = *(_DWORD *)(this + 64);
    v8 = v6;
    v3 = *(_DWORD *)(this + 68);
    v4 = *(_DWORD *)(this + 56);
    v7 = __PAIR64__(v5, v2);
    *(_QWORD *)(this + 56) = __PAIR64__(v5, v6) - __PAIR64__(v3, v2) + __PAIR64__(*(_DWORD *)(this + 60), v4);
    *(_DWORD *)(this + 68) = 0;
    *(_DWORD *)(this + 64) = 0;
  }
}
