int __thiscall sub_5B17B0(void *this, int a2, const char *a3, int a4)
{
  int v5; // eax
  const char *v7; // [esp+0h] [ebp-108h]
  char Buffer[256]; // [esp+8h] [ebp-100h] BYREF

  if ( dword_7E8E60 )
  {
    v5 = sub_5B16F0((int *)dword_7E8E60, a3);
    if ( v5 )
    {
      *(_DWORD *)(a2 + 544) = v5;
      *(_DWORD *)(a2 + 540) = a4;
      return 0;
    }
    else
    {
      sprintf(Buffer, "Could not find actor %s", a3);
      sub_591C60((int)this, -1, Buffer);
      return -1;
    }
  }
  else
  {
    sub_591C60((int)this, -1, "Could not find resposne %s", v7);
    return -1;
  }
}
