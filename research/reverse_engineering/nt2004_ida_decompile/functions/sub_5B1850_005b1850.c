int __thiscall sub_5B1850(void *this, int a2, const char *a3, const char *a4)
{
  _DWORD *v4; // esi
  int v5; // edi
  int v7; // eax
  _DWORD *v8; // eax
  int v9; // esi
  _DWORD *v10; // ebx
  _DWORD *v11; // eax
  int i; // eax
  _DWORD *v13; // eax
  const char *v14; // [esp+0h] [ebp-10Ch]
  char Buffer[256]; // [esp+Ch] [ebp-100h] BYREF

  v4 = (_DWORD *)dword_7E8E60;
  if ( dword_7E8E60 )
  {
    v5 = sub_5B16F0((int *)dword_7E8E60, a3);
    if ( v5 )
    {
      v7 = sub_5B1750(v4, a4);
      if ( v7 )
      {
        v8 = sub_5B15C0(v4, v5, v7);
        v9 = *(_DWORD *)(a2 + 548);
        v10 = v8;
        if ( v9 )
        {
          for ( i = *(_DWORD *)(v9 + 4); i; i = *(_DWORD *)(i + 4) )
            v9 = i;
          v13 = operator new(8u);
          *(_DWORD *)(v9 + 4) = v13;
          *v13 = v10;
          v13[1] = 0;
          return 0;
        }
        else
        {
          v11 = operator new(8u);
          *(_DWORD *)(a2 + 548) = v11;
          *v11 = v10;
          *(_DWORD *)(*(_DWORD *)(a2 + 548) + 4) = 0;
          return 0;
        }
      }
      else
      {
        sprintf(Buffer, "Could not find resposne %s", a4);
        return -1;
      }
    }
    else
    {
      sprintf(Buffer, "Could not find actor %s", a3);
      return -1;
    }
  }
  else
  {
    sub_591C60((int)this, -1, "Could not find resposne %s", v14);
    return -1;
  }
}
