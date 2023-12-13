#include <iostream>
#include <raylib.h>
#include <vector>
#include <time.h>


constexpr const int N = 50, WIDTH = 800, HEIGHT = 500, FPS = 60;
void exch(std::vector<int>&, int a, int b);


class rectangle
{
public:
	float height, pos;
	Rectangle r;

	rectangle(float i, float v) : pos(i), height(v)
	{
		r.x = WIDTH / N * pos + (WIDTH / N / 4);
		r.height = height / 100.0f * HEIGHT;
		r.y = HEIGHT - r.height;
		r.width = WIDTH / N / 2;
	}

	void draw()
	{
		DrawRectangleRec(r, MAROON);
	}

	void update(float v)
	{
		r.height = v / 100.0f * HEIGHT;
		r.y = HEIGHT - r.height;
	}
};


int main()
{
	srand((unsigned)time(NULL));

	auto v = std::vector<int>(N);
	for (int i = 0; i < N; ++i)
		v[i] = (rand() % 71) + 30;

	rectangle* rectangles = (rectangle*)malloc(N * sizeof(rectangle));
	for (int i = 0; i < N; ++i)
		rectangles[i] = rectangle(i, v[i]);

	InitWindow(WIDTH, HEIGHT, "Visualize Insertion Sort");
	SetTargetFPS(FPS);

	int i = 1, j = 1;
	while (!WindowShouldClose())
	{
		if (j <= 0) j = ++i;

		BeginDrawing();
		ClearBackground(RAYWHITE);

		if (i < N)
			if (v[j] < v[j - 1])
				exch(v, j, j - 1);

		for (int k = 0; k < N; ++k)
		{
			rectangles[k].update(v[k]);
			rectangles[k].draw();
		}

		if (i >= N) DrawText("Done!", WIDTH / 2 - WIDTH / 20, HEIGHT / 20, 50, BLUE);
		else --j;

		EndDrawing();
	}
	CloseWindow();

}

void exch(std::vector<int>& v, int a, int b)
{
	int tmp = v[a];
	v[a] = v[b];
	v[b] = tmp;
}