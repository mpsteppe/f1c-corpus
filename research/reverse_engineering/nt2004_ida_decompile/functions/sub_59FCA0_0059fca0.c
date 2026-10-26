int __thiscall sub_59FCA0(void *this, char *FileName, int a3)
{
  FILE *v4; // eax
  FILE *v5; // esi
  int v7; // edi
  void *v8; // ebx
  char Buffer[256]; // [esp+10h] [ebp-100h] BYREF

  v4 = fopen(FileName, aRb);
  v5 = v4;
  if ( v4 )
  {
    fseek(v4, 0, 2);
    v7 = ftell(v5);
    fseek(v5, 0, 0);
    v8 = operator new(v7);
    sub_5BED6F(v8, 1u, v7, v5);
    fclose(v5);
    if ( sub_5A6DF0((int)&unk_7E6B48, (int)v8, v7, (int)this, a3, 0) )
    {
      return -1;
    }
    else
    {
      sub_5BE8AE();
      return 0;
    }
  }
  else
  {
    sprintf(Buffer, "Error opening bitmap file %s", FileName);
    sub_591C60((int)this, -2, Buffer);
    return -2;
  }
}
