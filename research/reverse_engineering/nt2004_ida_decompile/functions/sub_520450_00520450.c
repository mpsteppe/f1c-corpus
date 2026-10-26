int __thiscall sub_520450(char *this, int a2, int a3, int a4, int a5)
{
  int result; // eax

  for ( result = sub_5367E0(384); result; result = sub_5367E0(384) )
  {
    result = sub_577B60(a4);
    if ( result == 1 )
      break;
    if ( !result )
    {
      if ( sub_578450(aFendercenter, (int)(this + 76), (int)(this + 84), (int)(this + 92), 0) )
        *this = 1;
      sub_578450(aFenderdragpara, (int)(this + 4), (int)(this + 12), (int)(this + 20), 0);
      sub_578450(aFenderliftpara, (int)(this + 28), (int)(this + 36), (int)(this + 44), 0);
      sub_578450(aFendersideways, (int)(this + 52), 0, 0, 0);
      if ( sub_578450(aFenderpeakyaw, (int)(this + 60), (int)(this + 68), 0, 0) )
        *(double *)(this + 60) = *(double *)(this + 60) * 0.0174532925199433;
      sub_430A90((char *)((a2 << 6) + a5 + 2992), a4, aFenderflareran, aFenderflareset_0, 1.0);
    }
  }
  return result;
}
