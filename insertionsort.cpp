/**
 * A program to visualize the insertion sort algorithm
 * A vector of size N is made with random values between MIN and MAX, inclusive
 * Rectangle heights correspond to magnitude of vector elements
 * Elements are sorted and graphic window is updated after every iteration, visualizing the sort
 *
 * @author Albert Bear
 */

#include <iostream>
#include <raylib.h>
#include <vector>
#include <time.h>

constexpr const int N      = 50,
		    WIDTH  = 800,
		    HEIGHT = 500,
		    FPS    = 60,
		    MAX    = 100,
		    MIN    = 10;


struct swap_
{
	template <typename T>
	void operator()(T& a, T& b)
	{
		T tmp{ a };
		a = b;
		b = tmp;
	}
} swap;


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
		v[i] = (rand() % (MAX - MIN + 1)) + MIN;

	auto rectangles = std::vector<rectangle>();

	for (int i = 0; i < N; ++i)
		rectangles.push_back(rectangle(i, v[i]));

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
				swap(v[j], v[j - 1]);

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
