/*
Find the total area covered by two rectilinear rectangles in a 2D plane.

Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

Assume that the total area is never beyond the maximum possible value of int.
*/

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
{
    auto commonArea = [&]() -> int
    {
        if (C <= E || A >= G || D <= F || B >= H)
            return 0;
    
        if (A <= E && B <= F && C >= G && D >= H)
            return (G - E) * (H - F);
    
        if (A >= E && B >= F && C <= G && D <= H)
            return (C - A) * (D - B);
    
        return (std::min(C, G) - std::max(A, E)) * (std::min(D, H) - std::max(B, F));
    };
    
    return (D - B) * (C - A) + (G - E) * (H - F) - commonArea();
}
